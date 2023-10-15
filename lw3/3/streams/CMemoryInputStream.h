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
	// ���������� ������� ���������� ����� ������ ������
	// ����������� ���������� std::ios_base::failuer � ������ ������
	bool IsEOF() const override
	{
		if (isClosed)
		{
			throw std::logic_error("stream is closed");
		}
		return std::cin.eof();
	}

	// ��������� ���� �� ������.
	// ����������� ���������� std::ios_base::failure � ������ ������
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
	// ��������� �� ������ ���� ������ �������� size ����, ��������� ��� � ������
	// �� ������ dstBuffer
	// ���������� ���������� ������� ����������� ����. ����������� ���������� � ������ ������
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override
	{
		if (isClosed)
		{
			throw std::logic_error("stream is closed");
		}
		std::cin.read((char*)dstBuffer, size);
		return std::cin.gcount();
	}

	// ��������� �����. �������� ��� ��� ����� ����� ������ ����������� ���������� logic_error
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

