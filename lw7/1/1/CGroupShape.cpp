#include "CGroupShape.h"
#include <stdexcept>
#include <memory>

CGroupShape::CGroupShape()
    :m_lineStyle(this)
    , m_fillStyle(this)
{
}

std::optional<RectD> CGroupShape::GetFrame() const
{
    //пустая группа не должна влиять на родителя
    if (m_shapes.empty())
    {
        return std::nullopt;
    }

    RectD compositeFrame{ std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), 0, 0 };

    for (auto& shape : m_shapes)
    {
        if (!shape->GetFrame().has_value())
        {
            continue;
        }

        RectD frame = shape->GetFrame().value();
        if (compositeFrame.left == std::numeric_limits<double>::max())
        {
            compositeFrame = frame;
        }

        if (compositeFrame.left > frame.left)
        {
            compositeFrame.width += compositeFrame.left - frame.left;
            compositeFrame.left = frame.left;
        }

        if (compositeFrame.top > frame.top)
        {
            compositeFrame.height += compositeFrame.top - frame.top;
            compositeFrame.top = frame.top;

        }

        if (compositeFrame.left + compositeFrame.width < frame.left + frame.width)
        {
            compositeFrame.width = frame.left + frame.width - compositeFrame.left;
        }

        if (compositeFrame.top + compositeFrame.height < frame.top + frame.height)
        {
            compositeFrame.height = frame.top + frame.height - compositeFrame.top;
        }
    }

    if (compositeFrame.left == std::numeric_limits<double>::max() 
        && compositeFrame.top == std::numeric_limits<double>::max() 
        && compositeFrame.width == 0 
        && compositeFrame.height == 0)
    {
        return std::nullopt;
    }
    else
    {
        return compositeFrame;
    }
}

void CGroupShape::SetFrame(const RectD& rect)
{
    if (!GetFrame().has_value())
    {
        return;
    }
    RectD currentFrame = GetFrame().value();

    double magnificationFactorLeft = rect.left / currentFrame.left;
    double magnificationFactorTop = rect.top / currentFrame.top;
    double magnificationFactorWidth = (rect.left + rect.width) / (currentFrame.left + currentFrame.width);
    double magnificationFactorHeight = (rect.top + rect.height) / (currentFrame.top + currentFrame.height);

    for (auto& shape : m_shapes)
    {
        if (!shape->GetFrame().has_value())
        {
            continue;
        }
        RectD frame = shape->GetFrame().value();
        shape->SetFrame({
            frame.left * magnificationFactorLeft,
            frame.top * magnificationFactorTop,
            (frame.left + frame.width) * magnificationFactorWidth - frame.left * magnificationFactorLeft,
            (frame.top + frame.height) * magnificationFactorHeight - frame.top * magnificationFactorTop,
            }
        );

    }
}

std::shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index)
{
    if (m_shapes.size() <= index)
    {
        throw std::out_of_range("out of range");
    }
    return m_shapes[index];
}

void CGroupShape::RemoveShapeAtIndex(size_t index)
{
    if (m_shapes.size() <= index)
    {
        throw std::out_of_range("out of range");
    }
    m_shapes.erase(m_shapes.begin() + index);
}

void CGroupShape::Draw(ICanvas& canvas)const
{
    for (auto& shape : m_shapes)
    {
        shape->Draw(canvas);
    }
}

void CGroupShape::EnumerateAllLineStyles(std::function<void(ILineStyle&)> callBack)
{
    for (auto& shape : m_shapes)
    {
        callBack(shape->GetOutlineStyle());
    }
}

void CGroupShape::EnumerateAllFillStyles(std::function<void(IFillStyle&)> callBack)
{
    for (auto& shape : m_shapes)
    {
        callBack(shape->GetFillStyle());
    }
}

size_t CGroupShape::GetShapesCount() const
{
    return m_shapes.size();
}

void CGroupShape::InsertShape(const std::shared_ptr<IShape>& shape, size_t position)
{
    //
    if (shape.get() == this)
    {
        throw std::logic_error("logic error");
    }
    if (position == std::numeric_limits<size_t>::max())
    {
        m_shapes.push_back(shape);
    }
    else
    {
        if (m_shapes.size() < position)
        {
            throw std::out_of_range("out of range");
        }

        m_shapes.insert(m_shapes.begin() + position, shape);
    }
}

std::shared_ptr<IGroupShape> CGroupShape::GetGroup()
{
    //копирование себя
    return std::make_shared<CGroupShape>(*this);
}

std::shared_ptr<const IGroupShape> CGroupShape::GetGroup() const
{
    return std::make_shared<CGroupShape>(*this);
}

ILineStyle& CGroupShape::GetOutlineStyle()
{
    return m_lineStyle;
}

const ILineStyle& CGroupShape::GetOutlineStyle() const
{
    return m_lineStyle;
}

void CGroupShape::SetOutlineColor(const std::optional<RGBAColor> color)
{
    m_lineStyle.SetColor(color);
}

void CGroupShape::SetOutlineWidth(const uint8_t width)
{
    m_lineStyle.SetWidth(width);
}

IFillStyle& CGroupShape::GetFillStyle()
{
    return m_fillStyle;
}

const IFillStyle& CGroupShape::GetFillStyle() const
{
    return m_fillStyle;
}


void CGroupShape::SetFillColor(const std::optional<RGBAColor> color)
{
    m_fillStyle.SetColor(color);
}
