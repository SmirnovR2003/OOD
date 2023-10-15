#pragma once
#include "Condiments.h"

// Тип ликера
enum class LiqueurType
{
	Chocolate,	// Шоколадный
	Nut,		// Ореховый
};

// Добавка "Ликер"
class CLiqueur : public CCondimentDecorator
{
public:
	CLiqueur(IBeveragePtr&& beverage, LiqueurType liqueurType)
		: CCondimentDecorator(move(beverage))
		, m_liqueurType(liqueurType)
	{}
protected:
	double GetCondimentCost()const override
	{
		return 50;
	}
	std::string GetCondimentDescription()const override
	{
		return std::string(m_liqueurType == LiqueurType::Chocolate ? "Chocolate" : "Nut")
			+ " liqueur";
	}
private:
	LiqueurType m_liqueurType;
};

