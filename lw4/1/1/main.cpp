
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
	sf::RenderWindow window(sf::VideoMode(800, 800), "Picture.png");
	CCanvas canvas(&window);

	CPainter painter;
	painter.DrawPicture(designer.CreateDraft(fIn), &canvas);


	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event) && event.type == sf::Event::Closed)
			window.close();

		window.display();
	}
}
