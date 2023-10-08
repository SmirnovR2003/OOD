#pragma once
#include "Condiments.h"

class CÑream : public CCondimentDecorator
{
public:
	CÑream(IBeveragePtr&& beverage)
		: CCondimentDecorator(move(beverage))
	{}
protected:
	double GetCondimentCost()const override
	{
		return 25;
	}

	std::string GetCondimentDescription()const override
	{
		return "Ñream";
	}
};


