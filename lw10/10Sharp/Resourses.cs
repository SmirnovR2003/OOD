#pragma once
namespace Resourses
{
    enum ShapeType
    {
        Triangle,
        Rectangle,
        Ellipse
    };

    struct Point
    {
        int x;
        int y;
    };

    struct Size
    {
        int width;
        int height;
    };

    struct Shape
    {
        Shape()
        {
        }
        Shape(ShapeType type)
            :m_type(type)
        {
        }
        ShapeType m_type = ShapeType::Ellipse;
        Point m_leftTop = { 0, 0 };
        Size m_size = { 100, 100 };
    };
}

