#pragma once
#include "Condiments.h"

class C�ream : public CCondimentDecorator
{
public:
	C�ream(IBeveragePtr&& beverage)
		: CCondimentDecorator(move(beverage))
	{}
protected:
	double GetCondimentCost()const override
	{
		return 25;
	}

	std::string GetCondimentDescription()const override
	{
		return "�ream";
	}
};


