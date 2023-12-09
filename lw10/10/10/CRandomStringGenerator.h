#pragma once
#include <string>
#include <ctime>
#include <random>

class CRandomStringGenerator
{
public:
	std::string Get()
	{
		std::string id;
		std::mt19937 gen((unsigned int)std::time(0));
		for (int i = 0; i < 20; i++)
		{
			id += 'a' + gen() % 26;
		}
		return id;
	}
};

