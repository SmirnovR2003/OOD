#include "shapes.h"
#include <unordered_map>
#include <iostream>
#include "ShapesDrawingStrategy.hpp"

using namespace std;

std::shared_ptr<IDrawingStrategy> GetDrawingStrategy(string type)
{
	if (type == "circle")
	{
		return make_shared<CircleDrawingStrategy>();
	}
	else if (type == "triangle")
	{
		return make_shared<TriangleDrawingStrategy>();
	}
	else if (type == "rectangle")
	{
		return make_shared<RectangleDrawingStrategy>();
	}
	else if (type == "text")
	{
		return make_shared<TextDrawingStrategy>();
	}
	else if (type == "line")
	{
		return make_shared<LineDrawingStrategy>();
	}
	else
	{
		return shared_ptr<IDrawingStrategy>();
	}
}

std::map<std::string, IDrawingStrategy> DRRAWING_STRATEGY
{
	{"circle", CircleDrawingStrategy()},
	{"triangle", TriangleDrawingStrategy()},
	{"rectangle", RectangleDrawingStrategy()},
	{"text", TextDrawingStrategy()},
	{"line", LineDrawingStrategy()}
};


shapes::ShapeConteiner::ShapeConteiner(string id, string hexColor, string type, shared_ptr<Shape> content) 
	:m_id(id)
	, m_type(type)
	, m_content(content)
	, m_hexColor(hexColor)
	, m_drawingStrategy(GetDrawingStrategy(type))
{
	SetColor(hexColor);
}


int HexadecimalToDecimal(string hex) {
	size_t hexLength = hex.length();
	double dec = 0;

	for (size_t i = 0; i < hexLength; ++i)
	{
		char b = hex[i];

		if (b >= 48 && b <= 57)
			b -= 48;
		else if (b >= 65 && b <= 70)
			b -= 55;

		dec += b * pow(16, ((hexLength - i) - 1));
	}

	return (int)dec;
}

void shapes::ShapeConteiner::SetColor(std::string hexColor)
{
	m_hexColor = hexColor;
	if (hexColor[0] == '#')
		hexColor = hexColor.erase(0, 1);

	m_color.r = HexadecimalToDecimal(hexColor.substr(0, 2));
	m_color.g = HexadecimalToDecimal(hexColor.substr(2, 2));
	m_color.b = HexadecimalToDecimal(hexColor.substr(4, 2));
}

sf::Color shapes::ShapeConteiner::GetColor()
{
	return m_color;
}

Shape* shapes::ShapeConteiner::GetContent()
{
	return m_content.get();
}

void shapes::ShapeConteiner::DrawShape(Canvas& canvas)
{
	Shape* shape = m_content.get();

	canvas.SetColor(m_color);
	m_drawingStrategy.get()->Draw(canvas, shape->GetInfoForDrawing(), m_color);
}

void shapes::ShapeConteiner::ShowInfo()
{
	std::cout << m_type << " " << m_id << " " << m_hexColor << " ";
	m_content.get()->ShowInfo();
}

void shapes::ShapeConteiner::ChangeShape(std::string type, std::shared_ptr<Shape> newShape)
{
	m_type = type;
	m_content = newShape;
	m_drawingStrategy = GetDrawingStrategy(type);
}

void shapes::Picture::MoveShape(std::string id, double dx, double dy)
{
	m_shapes.find(id)->second.GetContent()->MoveShape(dx, dy);
}

bool shapes::Picture::Contains(std::string id)
{
	return m_shapes.count(id) == 1;
}

void shapes::Picture::MovePicture(double dx, double dy)
{
	for (auto& shape : m_shapes)
	{
		shape.second.GetContent()->MoveShape(dx, dy);
	}
}

void shapes::Picture::DeleteShape(std::string id)
{
	m_shapes.erase(id);
}
//
//std::unordered_map<std::string, shapes::ShapeConteiner>& shapes::Picture::GetShapes()
//{
//	return m_shapes;
//}

void shapes::Picture::ChangeColor(std::string id, std::string hexColor)
{
	m_shapes.find(id)->second.SetColor(hexColor);

}

void shapes::Picture::ChangeShape(std::string id, std::string type, std::shared_ptr<Shape> newShape)
{
	m_shapes.find(id)->second.ChangeShape(type, newShape);
}

void shapes::Picture::DrawPicture()
{
	for (std::pair<std::string, shapes::ShapeConteiner> shape : m_shapes)
	{
		shape.second.DrawShape(m_canvas);
	}
}

void shapes::Picture::DrawShape(std::string id)
{
	m_shapes.find(id)->second.DrawShape(m_canvas);
}

void shapes::Picture::AddShape(std::string& id, std::string& hexColor, std::string& type, shared_ptr<Shape> content)
{
	ShapeConteiner shapeConteiner(id, hexColor, type, content);
	m_shapes.insert({ id, shapeConteiner });
}

void shapes::Picture::List()
{
	int shapeNumber = 0;
	for (auto& shape : m_shapes)
	{
		cout << ++shapeNumber << " ";
		shape.second.ShowInfo();
		cout << "\n";
	}
}

//void shapes::Picture::Display()
//{
//	m_canvas.Display();
//}
void shapes::Picture::ShowFinalPicture()
{
	m_canvas.ShowFinalPicture();
}
