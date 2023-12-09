#pragma once
#include "IOutputStreamDecorator.h"
class CCompress :
    public COutputStreamDecorator
{
public:
	CCompress(IOutputStreamPtr&& outputStream)
		:COutputStreamDecorator(std::move(outputStream))
	{
	}

	//write byte сделать с счетчиком байтов должно коректно работать WriteByte и WriteBlock
	//то же для декомпресии
	void WriteByte(uint8_t data)override
	{
		if (m_currentByteCounter == 0)
		{
			m_currentByte = data;
			m_currentByteCounter = 1;

		}
		else if (m_currentByteCounter == 255 || data != m_currentByte)
		{
			WriteDecoratedByte(m_currentByteCounter);
			WriteDecoratedByte(m_currentByte);
			m_currentByte = data;
			m_currentByteCounter = 1;
		}
		else 
		{
			m_currentByteCounter++;
		}
	}

	void WriteBlock(const void* srcData, std::streamsize size)override
	{
		uint8_t* charData = (uint8_t*) srcData;
		for (int i = 0; i < size; ++i)
		{
			WriteByte(charData[i]);
		}
	}

	//забыл close у вложенного потока
	void Close()override
	{
		WriteDecoratedByte(m_currentByteCounter);
		WriteDecoratedByte(m_currentByte);
		COutputStreamDecorator::Close();
	}

	uint8_t m_currentByteCounter = 0;
	uint8_t m_currentByte = 0;
};

