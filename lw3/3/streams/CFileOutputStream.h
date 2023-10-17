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
	// ���������� � ����� ������ ����
	// ����������� ���������� std::ios_base::failure � ������ ������
	void WriteByte(uint8_t data) override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		file << data;
	}

	// ���������� � ����� ���� ������ �������� size ����,
	// ��������������� �� ������ srcData,
	// � ������ ������ ����������� ���������� std::ios_base::failure
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

	// ��������� �����. �������� ��� ��� ����� ����� ������ ����������� ���������� logic_error
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

