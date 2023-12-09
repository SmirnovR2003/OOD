#pragma once
#include <functional>
#include "ILineStyle.h"

class ILineStyleEnumerator
{
public:
	virtual void EnumerateAllLineStyles(std::function<void(ILineStyle&)>) = 0;
	virtual ~ILineStyleEnumerator() = default;
};

