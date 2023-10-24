#pragma once
#include<string>
#include<memory>
#include "CShape.h"

class IShapeFactory
{

	//добавить виртуальный деструктор и обЪяснить зачем и где
public:
	virtual std::shared_ptr<CShape> CreateShape(const std::string& descr) = 0;
	~IShapeFactory() = default;
};

