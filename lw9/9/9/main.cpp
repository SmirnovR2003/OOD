#include <cmath>
#include <iostream>
#include <fstream>

#include "drawer.h"


int main()
{

	{
		std::ofstream out("out.bmp", std::ios::binary);
		Image img{ { 100, 100}, 0xffffff };

		//лишние пиксели в изображении в левом верхнем углу
		FillCircle(img, { 90, 50 }, 40, 0xffff00);
		FillCircle(img, { 50, 50 }, 40, 0xff0000);

		/*DrawLine(img, { 10, 90 }, { 10,80 }, 0xff0000);
		DrawLine(img, { 10,80 }, { 20,80 }, 0xff0000);
		DrawLine(img, { 20,80 }, { 20,90 }, 0xff0000);
		DrawLine(img, { 20, 90 }, { 10,90 }, 0xff0000);

		DrawLine(img, { 10, 80 }, { 20,80 }, 0x000000);
		DrawLine(img, { 20, 80 }, { 15,75 }, 0x000000);
		DrawLine(img, { 15,75 }, { 10,80 }, 0x000000);*/


		Print(img, out);
	}
}
