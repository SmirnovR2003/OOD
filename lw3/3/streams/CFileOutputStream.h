#pragma once
#include "IOutputStream.h"
#include<fstream>
class CFileOutputStream :
    public IOutputStream
{
public:
	CFileOutputStream(const char* fileName)
		:file(fileName, std::ofstream::binary)
		, isClosed(false)
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
		file << data;
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
		uint8_t* charData = (uint8_t*)srcData;
		for (int i = 0; i < size; i++)
		{
			file.put(charData[i]);
		}
	}

	// Закрывает поток. Операции над ним после этого должны выбрасывать исключение logic_error
	void Close()override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		file.close();

		isClosed = true;
	}
private:
	bool isClosed;
	std::ofstream file;
};

