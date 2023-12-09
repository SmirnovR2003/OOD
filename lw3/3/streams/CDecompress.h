#pragma once
#include <string>
#include "IInputStreamDecorator.h"
class CDecompress :
    public CInputStreamDecorator
{
public:
	CDecompress(IInputStreamPtr&& outputStream)
		:CInputStreamDecorator(std::move(outputStream))
	{
	}

	bool IsEOF() const override
	{
		if (m_currentByteCounter == 0)
		{
			return CInputStreamDecorator::IsEOF();
		}
		else
		{
			return false;
		}
	}

	uint8_t ReadByte() override
	{
		if (m_currentByteCounter == 0)
		{
			m_currentByteCounter = CInputStreamDecorator::ReadByte();
			m_currentByte = CInputStreamDecorator::ReadByte();
		}
		--m_currentByteCounter;
		return m_currentByte;
	}

	std::streamsize ReadBlock(void* srcData, std::streamsize size)override
	{
		uint8_t* charData = (uint8_t*)srcData;
		for (int i = 0; i < size; i++)
		{
			charData[i] = ReadByte();
		}
		return size;
	}
private:
	uint8_t m_currentByteCounter = 0;
	uint8_t m_currentByte = 0;
};

