#pragma once
#include "IOutputStream.h"
class CMemoryOutputStream :
    public IOutputStream
{
	CMemoryOutputStream(const char* fileName)
		:isClosed(false)
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
		std::cout << data;
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
		std::cout.write((char*)srcData, size);
	}

	// ��������� �����. �������� ��� ��� ����� ����� ������ ����������� ���������� logic_error
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

