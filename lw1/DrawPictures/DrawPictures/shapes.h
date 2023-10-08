#pragma once

#include <string>
#include<memory>
#include <vector>
#include <unordered_map>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Canvas.h"
#include "Shape.h"
#include "IDrawingStrategy.h"

namespace shapes
{
	class ShapeConteiner;

	class Picture
	{
	public:
		void MoveShape(std::string id, double dx, double dy);
		bool Contains(std::string id);
		void MovePicture(double dx, double dy);
		void DeleteShape(std::string id);
		void ChangeColor(std::string id, std::string hexColor);
		void ChangeShape(std::string id, std::string type, std::shared_ptr<Shape> newShape);
		void DrawPicture();
		void DrawShape(std::string id);
		void AddShape(std::string& id, std::string& hexColor, std::string& type, std::shared_ptr<Shape> content);
		void List();
		void ShowFinalPicture();

	private:
		std::unordered_map<std::string, ShapeConteiner> m_shapes;
		Canvas m_canvas;
	};

	class ShapeConteiner
	{
	public:
		ShapeConteiner(std::string id, std::string hexColor, std::string type, std::shared_ptr<Shape> content);
		void SetColor(std::string hexColor);
		sf::Color GetColor();
		Shape* GetContent();
		void DrawShape(Canvas& canvas);
		void ShowInfo();
		void ChangeShape(std::string type, std::shared_ptr<Shape> newShape);

	private:
		std::string m_id;
		std::string m_type;
		std::shared_ptr<Shape> m_content;
		sf::Color m_color;
		std::string m_hexColor;
		std::shared_ptr<IDrawingStrategy> m_drawingStrategy;
	};

}

