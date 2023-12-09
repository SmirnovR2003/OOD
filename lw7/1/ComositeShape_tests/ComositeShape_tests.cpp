#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../1/CGroupShape.h"
#include<sstream>
#include "../1/CRectangle.h"
#include "../1/CTriangle.h"
#include "../1/CEllipse.h"

using namespace std;

SCENARIO("GetFrame tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		CHECK(!shapes.GetFrame().has_value());
	}
	SECTION("Check with 1 shape")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect( { 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect));
		CHECK(shapes.GetFrame().has_value());
		CHECK(shapes.GetFrame().value().height == 100);
		CHECK(shapes.GetFrame().value().top == 100);
		CHECK(shapes.GetFrame().value().width == 100);
		CHECK(shapes.GetFrame().value().left == 100);
	}
	SECTION("Check with any shapes")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect1( { 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2( { 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		CRectangle rect3( { 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3));
		CHECK(shapes.GetFrame().has_value());
		CHECK(shapes.GetFrame().value().height == 200);
		CHECK(shapes.GetFrame().value().top == 50);
		CHECK(shapes.GetFrame().value().width == 200);
		CHECK(shapes.GetFrame().value().left == 50);
	}
}

SCENARIO("SetFrame tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		shapes.SetFrame({100,100,100,100});
		CHECK(!shapes.GetFrame().has_value());
	}
	SECTION("Check with 1 shape")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect( { 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect));
		CHECK(shapes.GetFrame().has_value());
		CHECK(shapes.GetFrame().value().height == 100);
		CHECK(shapes.GetFrame().value().top == 100);
		CHECK(shapes.GetFrame().value().width == 100);
		CHECK(shapes.GetFrame().value().left == 100);
		shapes.SetFrame({ 0,0,100,100 });
		CHECK(shapes.GetFrame().has_value());
		CHECK(shapes.GetFrame().value().height == 100);
		CHECK(shapes.GetFrame().value().top == 0);
		CHECK(shapes.GetFrame().value().width == 100);
		CHECK(shapes.GetFrame().value().left == 0);
	}
	SECTION("Check with any shapes")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect1( { 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2( { 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		CRectangle rect3( { 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3));
		CHECK(shapes.GetFrame().has_value());
		CHECK(shapes.GetFrame().value().height == 200);
		CHECK(shapes.GetFrame().value().top == 50);
		CHECK(shapes.GetFrame().value().width == 200);
		CHECK(shapes.GetFrame().value().left == 50);
	}
}

SCENARIO("GetFillStyle tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		CHECK(shapes.GetFillStyle().GetColor() == nullopt);
	}
	SECTION("Check with 1 shape")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		fillStyle.SetColor(0xff00ff);
		CRectangle rect({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect));
		CHECK(shapes.GetFillStyle().GetColor().value() == 0xff00ff);
	}
	SECTION("Check with any shapes with same color")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		fillStyle.SetColor(0xff00ff);
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3));
		CHECK(shapes.GetFillStyle().GetColor().value() == 0xff00ff);
	}

	SECTION("Check with any shapes with different color")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		fillStyle.SetColor(0xff00ff);
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		fillStyle.SetColor(0xfff0ff);
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3));
		CHECK(!shapes.GetOutlineStyle().GetColor().has_value());
	}
}

SCENARIO("SetFillStyle tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		shapes.SetFillColor(0xff00ff);
		CHECK(shapes.GetFillStyle().GetColor() == nullopt);
	}
	SECTION("Check with 1 shape")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect));
		shapes.SetFillColor(0xff00ff);
		CHECK(shapes.GetFillStyle().GetColor().value() == 0xff00ff);
	}
	SECTION("Check with any shapes")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3));
		shapes.SetFillColor(0xff00ff);
		CHECK(shapes.GetFillStyle().GetColor().value() == 0xff00ff);
	}
}

SCENARIO("GetOutlineStyle tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		CHECK(shapes.GetOutlineStyle().GetColor() == nullopt);
		CHECK(shapes.GetOutlineStyle().GetWidth() == nullopt);
	}
	SECTION("Check with 1 shape")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		lineStyle.SetColor(0xff00ff);
		lineStyle.SetWidth(10);
		CRectangle rect({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect));
		CHECK(shapes.GetOutlineStyle().GetColor().value() == 0xff00ff);
		CHECK(shapes.GetOutlineStyle().GetWidth().value() == 10);
	}
	SECTION("Check with any shapes with same color")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		lineStyle.SetColor(0xff00ff);
		lineStyle.SetWidth(10);
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3));
		CHECK(shapes.GetOutlineStyle().GetColor().value() == 0xff00ff);
		CHECK(shapes.GetOutlineStyle().GetWidth().value() == 10);
	}

	SECTION("Check with any shapes with different color")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		lineStyle.SetColor(0xff00ff);
		lineStyle.SetWidth(10);
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		lineStyle.SetColor(0xfff0ff);
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3));
		CHECK(!shapes.GetOutlineStyle().GetColor().has_value());
		CHECK(shapes.GetOutlineStyle().GetWidth().value() == 10);
	}
}

SCENARIO("SetOutlineStyle tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		shapes.SetOutlineColor(0xff00ff);
		shapes.SetOutlineWidth(10);
		CHECK(shapes.GetOutlineStyle().GetColor() == nullopt);
		CHECK(shapes.GetOutlineStyle().GetWidth() == nullopt);
	}
	SECTION("Check with 1 shape")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect));
		shapes.SetOutlineColor(0xff00ff);
		shapes.SetOutlineWidth(10);
		CHECK(shapes.GetOutlineStyle().GetColor().value() == 0xff00ff);
		CHECK(shapes.GetOutlineStyle().GetWidth().value() == 10);
	}
	SECTION("Check with any shapes")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3));
		shapes.SetOutlineColor(0xff00ff);
		shapes.SetOutlineWidth(10);
		CHECK(shapes.GetOutlineStyle().GetColor().value() == 0xff00ff);
		CHECK(shapes.GetOutlineStyle().GetWidth().value() == 10);
	}
}

SCENARIO("GetShapesCount tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		CHECK(shapes.GetShapesCount() == 0);
	}
	SECTION("Check with 1 shape")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect));
		CHECK(shapes.GetShapesCount() == 1);
	}
	SECTION("Check with any shapes")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3));
		CHECK(shapes.GetShapesCount() == 3);
	}
}

SCENARIO("InsertShape tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect));
		CHECK(shapes.GetShapesCount() == 1);
	}

	SECTION("Check with adding yourself")
	{
		CGroupShape shapes;
		//CHECK_THROWS(shapes.InsertShape(shared_ptr<CGroupShape>(&shapes)));
	}

	SECTION("Check with any shapes")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2),0);
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3),1);
		CHECK(shapes.GetShapesCount() == 3);
	}

	SECTION("Check with out of range")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		CHECK_THROWS( shapes.InsertShape(make_shared<CRectangle>(rect1), 1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2));
		CHECK_NOTHROW(shapes.InsertShape(make_shared<CRectangle>(rect1), 1));
	}
}

SCENARIO("GetShapeAtIndex tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		CHECK(shapes.GetShapesCount() == 0);
		CHECK_THROWS(shapes.GetShapeAtIndex(0));
	}

	SECTION("Check with any shapes")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2),0);
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3),1);
		CHECK(shapes.GetShapesCount() == 3);
		CHECK_NOTHROW(shapes.GetShapeAtIndex(0));
		CHECK_NOTHROW(shapes.GetShapeAtIndex(1));
		CHECK_NOTHROW(shapes.GetShapeAtIndex(2));
		CHECK_THROWS(shapes.GetShapeAtIndex(3));
	}
}

SCENARIO("RemoveShapeAtIndex tests")
{
	SECTION("Check with empty groupShape")
	{
		CGroupShape shapes;
		CHECK(shapes.GetShapesCount() == 0);
		CHECK_THROWS(shapes.RemoveShapeAtIndex(0));
	}

	SECTION("Check with any shapes")
	{
		CGroupShape shapes;
		CSimpleFillStyle fillStyle;
		CSimpleLineStyle lineStyle;
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));
		CRectangle rect2({ 200, 200 }, 50, 50, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect2),0);
		CRectangle rect3({ 50, 50 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect3),1);
		CHECK(shapes.GetShapesCount() == 3);
		CHECK_THROWS(shapes.RemoveShapeAtIndex(3));
		CHECK_NOTHROW(shapes.RemoveShapeAtIndex(2));
		CHECK_NOTHROW(shapes.RemoveShapeAtIndex(1));
		CHECK_NOTHROW(shapes.RemoveShapeAtIndex(0));
	}
}

class CMokeCanvas : public ICanvas
{
public:
	CMokeCanvas(ostream& out)
		:m_out(out)
	{}
	void SetLineStyle(const ILineStyle& style)
	{
		m_out << "SetLineStyle color: " << (style.GetColor().has_value() ? style.GetColor().value() : -1)
			<< " width: " << (style.GetWidth().has_value() ? style.GetWidth().value() : -1) << "\n";
	}
	void BeginFill(RGBAColor color)
	{
		m_out << "BeginFill color: " << color << "\n";

	}
	void EndFill()
	{
		m_out << "EndFill\n";
	}
	void MoveTo(double x, double y)
	{
		m_out << "MoveTo " << x << " " << y << "\n";
	}
	void LineTo(double x, double y)
	{
		m_out << "LineTo " << x << " " << y << "\n";

	}
	void DrawEllipse(double left, double top, double width, double height)
	{
		m_out << "DrawEllipse " << left << " " << top << " " << width << " " << height <<"\n";
	}
	
	ostream& m_out;
};

SCENARIO("Draw tests")
{
	SECTION("Check with empty groupShape")
	{
		ostringstream ostr;
		CMokeCanvas canvas(ostr);
		CGroupShape shapes;
		CHECK(shapes.GetShapesCount() == 0);
		shapes.Draw(canvas);
		CHECK(ostr.str() == "");
	}

	SECTION("Check with any shapes")
	{
		ostringstream ostr;
		CMokeCanvas canvas(ostr);
		CGroupShape shapes;

		CSimpleFillStyle fillStyle;
		fillStyle.SetColor(0xff00ff);
		CSimpleLineStyle lineStyle;
		lineStyle.SetColor(0xff00ff);
		lineStyle.SetWidth(10);
		CRectangle rect1({ 100, 100 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CRectangle>(rect1));

		CTriangle triangle({ 200, 200 }, { 50, 50 }, {200, 100}, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CTriangle>(triangle));

		CEllipse ellipse({ 500, 500 }, 100, 100, fillStyle, lineStyle);
		shapes.InsertShape(make_shared<CEllipse>(ellipse));

		shapes.Draw(canvas);
		CHECK(ostr.str() == "SetLineStyle color: 16711935 width: 10\n"
			"BeginFill color: 16711935\n"
			"MoveTo 100 100\n"
			"LineTo 200 100\n"
			"LineTo 200 200\n"
			"LineTo 100 200\n"
			"LineTo 100 100\n"
			"EndFill\n"
			"SetLineStyle color: 16711935 width: 10\n"
			"BeginFill color: 16711935\n"
			"MoveTo 200 200\n"
			"LineTo 50 50\n"
			"LineTo 200 100\n"
			"LineTo 200 200\n"
			"EndFill\n"
			"SetLineStyle color: 16711935 width: 10\n"
			"BeginFill color: 16711935\n"
			"DrawEllipse 500 500 200 200\n"
			"EndFill\n");
	}
}