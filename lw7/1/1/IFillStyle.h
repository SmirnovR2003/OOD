#pragma once
#include <optional>
#include "CommonTypes.h"

class IFillStyle
{
public:
	virtual std::optional<RGBAColor> GetColor()const = 0;
	virtual void SetColor(std::optional<RGBAColor> color) = 0;

	virtual ~IFillStyle() = default;
};
