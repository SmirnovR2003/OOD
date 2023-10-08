#pragma once
#include "Beverages.h"



class CMilkshake : public CBeverage
{
public:
	CMilkshake(const std::string& description = "Milkshake")
		:CBeverage(description)
	{}

	double GetCost() const override
	{
		return 80;
	}
};

class CSmallMilkshake : public CMilkshake
{
public:
	CSmallMilkshake()
		:CMilkshake("Small Milkshake")
	{}

	double GetCost() const override
	{
		return 50;
	}
};

class CMediumMilkshake : public CMilkshake
{
public:
	CMediumMilkshake()
		:CMilkshake("Medium Milkshake")
	{}

	double GetCost() const override
	{
		return 60;
	}
};

class CLargeMilkshake : public CMilkshake
{
public:
	CLargeMilkshake()
		:CMilkshake("Large Milkshake")
	{}

	double GetCost() const override
	{
		return 80;
	}
};