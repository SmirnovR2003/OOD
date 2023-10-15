#pragma once
#include "IOutputStream.h"
class CMemoryOutputStream :
    public IOutputStream
{
	CMemoryOutputStream(const char* fileName)
		:isClosed(false)
	{
	}
	// Записывает в поток данных байт
	// Выбрасывает исключение std::ios_base::failure в случае ошибки
	void WriteByte(uint8_t data) override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		std::cout << data;
	}

	// Записывает в поток блок данных размером size байт,
	// располагающийся по адресу srcData,
	// В случае ошибки выбрасывает исключение std::ios_base::failure
	void WriteBlock(const void* srcData, std::streamsize size)override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		std::cout.write((char*)srcData, size);
	}

	// Закрывает поток. Операции над ним после этого должны выбрасывать исключение logic_error
	void Close()override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		isClosed = true;
	}
private:
	bool isClosed = true;
};

