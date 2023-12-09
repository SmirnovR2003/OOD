#pragma once

#include <functional>
#include "IFillStyle.h"

class IFillStyleEnumerator
{
public:
	virtual void EnumerateAllFillStyles(std::function<void(IFillStyle&)>) = 0;
	virtual ~IFillStyleEnumerator() = default;
};

