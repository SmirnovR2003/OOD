#pragma once
#include "IInputStreamDecorator.h"
#include <vector>
#include <algorithm>
#include <random>
class CDecrypt :
    public CInputStreamDecorator
{
public:
	CDecrypt(IInputStreamPtr&& inputStream, unsigned int key)
		:CInputStreamDecorator(std::move(inputStream))
	{
		std::vector<uint8_t> cryptVector(255);
		for (int k = 0; k < 255; ++k)
		{
			cryptVector[k] = k;
		}
		shuffle(cryptVector.begin(), cryptVector.end(), std::mt19937(key));

		decryptVector.resize(255);
		for (int k = 0; k < 255; ++k)
		{
			decryptVector[cryptVector[k]] = k;
		}

	}

	uint8_t ReadByte()override
	{
		uint8_t byte = CInputStreamDecorator::ReadByte();
		return decryptVector[byte];
	}

	std::streamsize ReadBlock(void* srcData, std::streamsize size)override
	{
		uint8_t* charData = (uint8_t*)srcData;
		for (int i = 0; i < size; ++i)
		{
			charData[i] = ReadByte();
		}
		return size;
	}
private:

	std::vector<uint8_t> decryptVector{};
};

