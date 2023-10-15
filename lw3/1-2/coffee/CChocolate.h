#pragma once
#include <memory>
#include "Condiments.h"

int CheckChocolateQuantity(unsigned quantity)
{
	if (quantity > 5)
	{
		throw std::exception("maximum 5 slices of chocolate");
	}
	else
	{
		return quantity;
	}
}

// добавка шоколадных долек
class CChocolate : public CCondimentDecorator
{
public:
	CChocolate(IBeveragePtr&& beverage, unsigned quantity = 1)
		: CCondimentDecorator(move(beverage))
		//убрать доп функцию
		, m_quantity(CheckChocolateQuantity(quantity))
	{}
protected:
	double GetCondimentCost()const override
	{
		return 10.0 * m_quantity;
	}
	std::string GetCondimentDescription()const override
	{
		return "Chocolate x " + std::to_string(m_quantity);
	}
private:
	unsigned m_quantity;
};

