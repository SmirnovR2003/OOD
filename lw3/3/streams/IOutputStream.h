#pragma once
#include <iostream>

class IOutputStream
{
public:
	// ���������� � ����� ������ ����
	// ����������� ���������� std::ios_base::failure � ������ ������
	virtual void WriteByte(uint8_t data) = 0;

	// ���������� � ����� ���� ������ �������� size ����,
	// ��������������� �� ������ srcData,
	// � ������ ������ ����������� ���������� std::ios_base::failure
	virtual void WriteBlock(const void* srcData, std::streamsize size) = 0;

	// ��������� �����. �������� ��� ��� ����� ����� ������ ����������� ���������� logic_error
	virtual void Close() = 0;

	virtual ~IOutputStream() = default;
};

typedef std::unique_ptr<IOutputStream> IOutputStreamPtr;

