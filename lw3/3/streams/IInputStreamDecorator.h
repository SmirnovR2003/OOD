#pragma once
#include "IInputStream.h"
//������� ��� ����� ��������� �� ���� �� ���������� �����������
class CInputStreamDecorator :
    public IInputStream
{
public:
	// ���������� ������� ���������� ����� ������ ������
	// ����������� ���������� std::ios_base::failuer � ������ ������
	bool IsEOF() const override
	{
		return m_inputStream.get()->IsEOF();
	}

	// ��������� ���� �� ������.
	// ����������� ���������� std::ios_base::failure � ������ ������
	uint8_t ReadByte() override
	{
		return m_inputStream->ReadByte();
	}

	// ��������� �� ������ ���� ������ �������� size ����, ��������� ��� � ������
	// �� ������ dstBuffer
	// ���������� ���������� ������� ����������� ����. ����������� ���������� � ������ ������
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override
	{

		return m_inputStream.get()->ReadBlock(dstBuffer, size);
	}

	// ��������� �����. �������� ��� ��� ����� ����� ������ ����������� ���������� logic_error
	void Close()override
	{
		m_inputStream.get()->Close();
	}


protected:
	CInputStreamDecorator(IInputStreamPtr&& inputStream)
		: m_inputStream(std::move(inputStream))
	{
	}

	void ReadOneByte(uint8_t& byte)
	{
		byte = m_inputStream->ReadByte();
	}

	void ReadTwoBytes(uint8_t& byte1, uint8_t& byte2)
	{
		byte1 = m_inputStream->ReadByte();
		byte2 = m_inputStream->ReadByte();
	}
private:
	IInputStreamPtr m_inputStream;
};

