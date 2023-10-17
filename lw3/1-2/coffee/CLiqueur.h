#pragma once
#include "Condiments.h"

// ��� ������
enum class LiqueurType
{
	Chocolate,	// ����������
	Nut,		// ��������
};

// ������� "�����"
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

