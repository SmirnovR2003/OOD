
#include <iostream>
#include <fstream>
#include "CDesigner.h"
#include "CPainter.h"
#include "CCanvas.h"
#include "CShapeFactory.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

int main()
{
	ifstream fIn("in.txt");
	CShapeFactory shapeFactory;
	CDesigner designer(make_unique<CShapeFactory>(shapeFactory) );
	sf::RenderWindow tar(sf::VideoMode(800, 800), "Picture.png");
	CCanvas canvas(&tar);

	CPainter painter;
	painter.DrawPicture(designer.CreateDraft(fIn), &canvas);
	canvas.ShowFinalPicture();
}
