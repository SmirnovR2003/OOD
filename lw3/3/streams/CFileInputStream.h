#pragma once
#include "IInputStream.h"
#include <fstream>
class CFileInputStream :
    public IInputStream
{
public:
	CFileInputStream(const char* fileName)
		:file(fileName, std::ios::in | std::ios::binary)
		, isClosed(false)
	{
	}
	// Возвращает признак достижения конца данных потока
	// Выбрасывает исключение std::ios_base::failuer в случае ошибки
	bool IsEOF() const override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		return file.eof();
	}

	// Считывает байт из потока.
	// Выбрасывает исключение std::ios_base::failure в случае ошибки
	uint8_t ReadByte() override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		uint8_t byte;
		file >> byte;
		return byte;
	}
	// Считывает из потока блок данных размером size байт, записывая его в память
	// по адресу dstBuffer
	// Возвращает количество реально прочитанных байт. Выбрасывает исключение в случае ошибки
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		file.read((char*)dstBuffer, size);
		return file.gcount();
	}

	// Закрывает поток. Операции над ним после этого должны выбрасывать исключение logic_error
	void Close() override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		file.close();
		isClosed = true;
	}
private:
	bool isClosed = true;
	std::ifstream file;
};

