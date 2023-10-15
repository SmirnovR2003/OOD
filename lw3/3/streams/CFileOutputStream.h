#pragma once
#include "IOutputStream.h"
#include<fstream>
class CFileOutputStream :
    public IOutputStream
{
public:
	CFileOutputStream(const char* fileName)
		:file(fileName, std::ios::out | std::ios::binary)
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
		file.write((char*)srcData, size);
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
	bool isClosed = true;
	std::ofstream file;
};

