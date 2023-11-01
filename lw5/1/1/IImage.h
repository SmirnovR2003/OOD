#pragma once
#include <string>
#include <filesystem>


/*
Изображение
*/
class IImage
{
public:
	// Возвращает путь относительно каталога документа
	virtual std::filesystem::path GetPath()const = 0;
	// Ширина изображения в пикселях
	virtual unsigned int GetWidth()const = 0;
	// Высота изображения в пикселях
	virtual unsigned int GetHeight()const = 0;
	// Изменяет размер изображения
	virtual void Resize(unsigned int width, unsigned int height) = 0;
	virtual std::string GetInfo()const = 0;
	virtual ~IImage() = default;
};
