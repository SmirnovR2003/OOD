#pragma once
#include <vector>
#include "IOutputStreamDecorator.h"
#include <algorithm>
#include <random>
class CCrypt :
    public COutputStreamDecorator
{
public:
	CCrypt(IOutputStreamPtr&& outputStream, unsigned int key)
		:COutputStreamDecorator(std::move(outputStream))
	{
		cryptVector.resize(255);
		for (int k = 0; k < 255; ++k)
		{
			cryptVector[k] = k;
		}
		shuffle(cryptVector.begin(), cryptVector.end(), std::mt19937(key));
	}

	void WriteByte(uint8_t data)override
	{
		WriteDecoratedByte(cryptVector[data]);
	}

	void WriteBlock(const void* srcData, std::streamsize size)override
	{
		uint8_t* charData = (uint8_t*)srcData;
		for (int i = 0; i < size; ++i)
		{
			WriteByte(charData[i]);
		}
	}
private:

	std::vector<uint8_t> cryptVector{};
};

