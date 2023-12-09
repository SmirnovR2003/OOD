#pragma once
#include <optional>
#include "CommonTypes.h"

class ILineStyle
{
public:

	virtual std::optional<RGBAColor> GetColor()const = 0;
	virtual void SetColor(std::optional<RGBAColor> color) = 0;

	virtual std::optional<uint8_t> GetWidth()const = 0;
	virtual void SetWidth(uint8_t outLineWidth) = 0;

	virtual ~ILineStyle() = default;

};

