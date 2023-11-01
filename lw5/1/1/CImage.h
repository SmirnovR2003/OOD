#pragma once
#include "IImage.h"
#include <filesystem>
#include <chrono>
#include <ctime>
#include <random>
#include <algorithm>

class CImage :
    public IImage
{
public:
	CImage(std::vector<std::shared_ptr<CDocumentItem>>* documentItems, const std::string& path, unsigned int width, unsigned int height)
		: m_documentItems(documentItems)
		, m_width(width)
		, m_height(height)
	{
		//дублтррование
		if (m_width > 10000 || m_width < 1)
		{
			throw std::invalid_argument("image width must be from 1 to 10000");
		}
		if (m_height > 10000 || m_height < 1)
		{
			throw std::invalid_argument("image height must be from 1 to 10000");
		}

		//вынеси генерацию в отдельный класс
		//вынести создание файлов в команды
		std::string newFileName;
		std::mt19937 gen((unsigned int)std::time(0));
		for (int i = 0; i < 20; i++) 
		{
			newFileName += 'a' + gen() % 26;
		}

		for (auto i = path.begin() + path.find_last_of('.'); i != path.end(); i++)
		{
			newFileName += *i;
		}

		std::filesystem::path sourceFile = path;
		m_documentPath = "images\\";
		m_documentPath = m_documentPath / newFileName;

		std::filesystem::create_directories(m_documentPath.parent_path());
		std::filesystem::copy_file(sourceFile, m_documentPath.parent_path() / m_documentPath.filename(), std::filesystem::copy_options::overwrite_existing);
	}
	// Возвращает путь относительно каталога документа
	std::filesystem::path GetPath()const override
	{
		return m_documentPath;
	};

	// Ширина изображения в пикселях
	unsigned int GetWidth()const override
	{
		return m_width;
	};

	// Высота изображения в пикселях
	unsigned int GetHeight()const override
	{
		return m_height;
	};

	// Изменяет размер изображения
	void Resize(unsigned int width, unsigned int height) override
	{
		if (m_width > 10000 || m_width < 1)
		{
			throw std::invalid_argument("image width must be from 1 to 10000");
		}
		if (m_height > 10000 || m_height < 1)
		{
			throw std::invalid_argument("image height must be from 1 to 10000");
		}
		m_width = width;
		m_height = height;
	};

	std::string GetInfo()const
	{
		return "Image: " + std::to_string(m_width) + " " + std::to_string(m_height) + " " + m_documentPath.string();
	}

	~CImage()
	{

	}

private:

	std::vector<std::shared_ptr<CDocumentItem>>* m_documentItems;
	std::filesystem::path m_documentPath;
	unsigned int m_width;
	unsigned int m_height;
};

