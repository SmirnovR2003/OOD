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
	// ���������� ������� ���������� ����� ������ ������
	// ����������� ���������� std::ios_base::failuer � ������ ������
	bool IsEOF() const override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		return file.eof();
	}

	// ��������� ���� �� ������.
	// ����������� ���������� std::ios_base::failure � ������ ������
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
	// ��������� �� ������ ���� ������ �������� size ����, ��������� ��� � ������
	// �� ������ dstBuffer
	// ���������� ���������� ������� ����������� ����. ����������� ���������� � ������ ������
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override
	{
		if (isClosed)
		{
			throw std::logic_error("file is closed");
		}
		file.read((char*)dstBuffer, size);
		return file.gcount();
	}

	// ��������� �����. �������� ��� ��� ����� ����� ������ ����������� ���������� logic_error
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

