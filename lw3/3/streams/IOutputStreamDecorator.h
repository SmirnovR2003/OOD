#pragma once
#include "IOutputStream.h"

// � ��� ����� ������ ������������� �����������
class COutputStreamDecorator :
    public IOutputStream
{
public:

	// ��������� �����. �������� ��� ��� ����� ����� ������ ����������� ���������� logic_error
	void Close()override
	{
		m_outputStream->Close();
	}


protected:
	COutputStreamDecorator(IOutputStreamPtr&& outputStream)
		: m_outputStream(move(outputStream))
	{
	}


	void WriteDecoratedByte(uint8_t data)
	{
		m_outputStream->WriteByte(data);
	}
private:
	IOutputStreamPtr m_outputStream;
};

