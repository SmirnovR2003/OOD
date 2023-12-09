#pragma once
#include "CommonTypes.h"
#include "IDrawable.h"
#include <memory>
#include <optional>
#include "IFillStyle.h"
#include "ILineStyle.h"


class IGroupShape;

class IShape : public IDrawable
{
public:
	virtual std::optional<RectD> GetFrame()const = 0;
	virtual void SetFrame(const RectD& rect) = 0;

	virtual ILineStyle& GetOutlineStyle() = 0;
	virtual const ILineStyle& GetOutlineStyle()const = 0;
	virtual void SetOutlineColor(const std::optional<RGBAColor> color) = 0;
	virtual void SetOutlineWidth(const uint8_t width) = 0;

	virtual IFillStyle& GetFillStyle() = 0;
	virtual const IFillStyle& GetFillStyle()const = 0;
	virtual void SetFillColor(const std::optional<RGBAColor> color) = 0;

	virtual std::shared_ptr<IGroupShape> GetGroup() = 0;
	virtual std::shared_ptr<const IGroupShape> GetGroup() const = 0;

	virtual ~IShape() = default;
};

