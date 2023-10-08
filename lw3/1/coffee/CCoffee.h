#pragma once
#include "Beverages.h"

class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		:CBeverage(description)
	{}

	double GetCost() const override
	{
		return 60;
	}
};

class CStandartCappuccino : public CCoffee
{
public:
	CStandartCappuccino()
		:CCoffee("Standart Cappuccino")
	{}

	double GetCost() const override
	{
		return 80;
	}
};

class CDoubleCappuccino : public CCoffee
{
public:
	CDoubleCappuccino()
		:CCoffee("Double Cappuccino")
	{}

	double GetCost() const override
	{
		return 120;
	}
};

class CStandartLatte : public CCoffee
{
public:
	CStandartLatte()
		:CCoffee("Standart Latte")
	{}

	double GetCost() const override
	{
		return 90;
	}
};

class CDoubleLatte : public CCoffee
{
public:
	CDoubleLatte()
		:CCoffee("Double Latte")
	{}

	double GetCost() const override
	{
		return 130;
	}
};
