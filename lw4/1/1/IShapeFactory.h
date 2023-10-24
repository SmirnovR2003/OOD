#pragma once
#include<string>
#include<memory>
#include "CShape.h"

class IShapeFactory
{

	//�������� ����������� ���������� � ��������� ����� � ���
public:
	virtual std::shared_ptr<CShape> CreateShape(const std::string& descr) = 0;
	~IShapeFactory() = default;
};

