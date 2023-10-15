#pragma once
#include "Beverages.h"

class CTea : public CBeverage
{
public:
	CTea(const std::string& description = "Tea")
		:CBeverage(description)
	{}

	double GetCost() const override
	{
		return 30;
	}
};

class CRedTea : public CTea
{
public:
	CRedTea()
		:CTea("Red Tea")
	{}
};

class CYellowTea : public CTea
{
public:
	CYellowTea()
		:CTea("Yellow Tea")
	{}
};

class CBlackTea : public CTea
{
public:
	CBlackTea()
		:CTea("Black Tea")
	{}
};

class CGreenTea : public CTea
{
public:
	CGreenTea()
		:CTea("Green Tea")
	{}
};

