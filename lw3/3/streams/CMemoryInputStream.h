#pragma once
#include "IInputStream.h"
class CMemoryInputStream :
    public IInputStream
{
public:
	CMemoryInputStream()
		:isClosed(false)
	{
	}
	// Возвращает признак достижения конца данных потока
	// Выбрасывает исключение std::ios_base::failuer в случае ошибки
	bool IsEOF() const override
	{
		if (isClosed)
		{
			throw std::logic_error("stream is closed");
		}
		return std::cin.eof();
	}

	// Считывает байт из потока.
	// Выбрасывает исключение std::ios_base::failure в случае ошибки
	uint8_t ReadByte() override
	{
		if (isClosed)
		{
			throw std::logic_error("stream is closed");
		}
		uint8_t byte;
		std::cin >> byte;
		return byte;
	}
	// Считывает из потока блок данных размером size байт, записывая его в память
	// по адресу dstBuffer
	// Возвращает количество реально прочитанных байт. Выбрасывает исключение в случае ошибки
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override
	{
		if (isClosed)
		{
			throw std::logic_error("stream is closed");
		}
		std::cin.read((char*)dstBuffer, size);
		return std::cin.gcount();
	}

	// Закрывает поток. Операции над ним после этого должны выбрасывать исключение logic_error
	void Close() override
	{
		if (isClosed)
		{
			throw std::logic_error("stream is closed");
		}
		isClosed = true;
	}
private:
	bool isClosed = true;
};

