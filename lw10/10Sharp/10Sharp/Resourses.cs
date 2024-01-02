
namespace _10Sharp
{
    public enum ShapeType
    {
        Triangle,
        Rectangle,
        Ellipse
    };

    public struct Point
    {
        public int x;
        public int y;

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    };

    public struct Size
    {
        public int width;
        public int height;

        public Size(int width, int height)
        {
            this.width = width;
            this.height = height;
        }
    };

    public class Shape
    {
        public Shape(ShapeType type)
        {
            this.m_type = type;
            this.m_leftTop.x = 0;
            this.m_leftTop.y = 0;
            this.m_size.height = 100;
            this.m_size.width = 100;
        }
        public ShapeType m_type;
        public Point m_leftTop;
        public Size m_size;
    };
}

