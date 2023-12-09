#pragma once
#include "IGroupShape.h"
#include "ILineStyleEnumerator.h"
#include <vector>
#include "CCompositeLineStyle.h"
#include "CCompositeFillStyle.h"


//диаграмма нет связи compositestyle и istyle
class CGroupShape :
    public IGroupShape,
	//сделать приватными иперенести в CGroupShape
	private ILineStyleEnumerator,
	private IFillStyleEnumerator,
	public std::enable_shared_from_this<IShape>
{
public:
	CGroupShape();
	std::optional<RectD> GetFrame()const override;
	void SetFrame(const RectD& rect)override;

	ILineStyle& GetOutlineStyle()override;
	const ILineStyle& GetOutlineStyle()const override;
	void SetOutlineColor(const std::optional<RGBAColor> color)override;
	void SetOutlineWidth(const uint8_t width) override;

	IFillStyle& GetFillStyle()override;
	const IFillStyle& GetFillStyle()const override;
	void SetFillColor(const std::optional<RGBAColor> color)override;

	std::shared_ptr<IGroupShape> GetGroup()override;
	std::shared_ptr<const IGroupShape> GetGroup() const override;

	size_t GetShapesCount()const override;
	void InsertShape(const std::shared_ptr<IShape>& shape, size_t position = std::numeric_limits<size_t>::max()) override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index)override;
	void RemoveShapeAtIndex(size_t index)override;

	void Draw(ICanvas& canvas)const override;

private:
	void EnumerateAllLineStyles(std::function<void(ILineStyle&)> callBack)override;
	void EnumerateAllFillStyles(std::function<void(IFillStyle&)> callBack)override;

	std::vector<std::shared_ptr<IShape>> m_shapes;
	CCompositeLineStyle m_lineStyle;
	CCompositeFillStyle m_fillStyle;
};

