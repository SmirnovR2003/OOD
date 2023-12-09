#include "image.h"
#include "CoW.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

/**
 * Конструирует изображение заданного размера. Если размеры не являются положительными,
 * выбрасывает исключение std::out_of_range.
 */
Image::Image(Size size, uint32_t color)
	:m_size(size)
	, m_image(std::vector<std::vector<CoW<Tile>>>(
		m_size.width / Tile::SIZE + ((m_size.width % Tile::SIZE > 0) ? 1 : 0), std::vector<CoW<Tile>>(
			m_size.height / Tile::SIZE + ((m_size.height % Tile::SIZE > 0) ? 1 : 0), CoW<Tile>(color)
			)
		))
		
{
}

// Возвращает размер изображения в пикселях.
Size Image::GetSize() const noexcept
{
	/* Реализуйте метод самостоятельно. */

	return m_size;
}

/**
 * Возвращает «цвет» пикселя в указанных координатах.Если координаты выходят за пределы
 * изображения, возвращает «пробел».
 */
uint32_t Image::GetPixel(Point p) const noexcept
{
	if (IsPointInSize(p, m_size))
	{
		return m_image[p.x / Tile::SIZE][p.y / Tile::SIZE]->GetPixel({ p.x % Tile::SIZE, p.y % Tile::SIZE });
	}
	else
	{
		return ' ';
	}
}

/**
 * Задаёт «цвет» пикселя в указанных координатах. Если координаты выходят за пределы изображения
 * действие игнорируется.
 */
void Image::SetPixel(Point p, uint32_t color)
{
	if (IsPointInSize(p, m_size))
	{
		//назвние переменной
		auto im = (m_image[p.x / Tile::SIZE][p.y / Tile::SIZE].Write());
		std::move(im)->SetPixel({ p.x % Tile::SIZE, p.y % Tile::SIZE }, color);
	}
}

/**
 * Выводит в поток out изображение в виде символов.
 */ 
void Print(const Image& img, std::ostream& out)
{
	const auto size = img.GetSize();
	cv::Mat imgBmp(size.height,size.width, CV_8UC3);
	for (int y = 0; y < size.height; ++y)
	{
		for (int x = 0; x < size.width; ++x)
		{
			auto rgb = img.GetPixel({ x, y });

			imgBmp.at<cv::Vec3b>(y, x)[2] = static_cast<int>((rgb >> 16) & 0xff);
			imgBmp.at<cv::Vec3b>(y, x)[1] = static_cast<int>((rgb >> 8) & 0xff);
			imgBmp.at<cv::Vec3b>(y, x)[0] = static_cast<int>(rgb & 0xff);

			out << static_cast<char>((rgb >> 16) & 0xff);
			out << static_cast<char>((rgb >> 8) & 0xff);
			out << static_cast<char>(rgb & 0xff);
		}
		out << '\n';
	}
	cv::imwrite("out.bmp", imgBmp);
}

/**
 * Загружает изображение из pixels. Линии изображения разделяются символами \n.
 * Размеры картинки определяются по количеству переводов строки и самой длинной линии.
 */
Image LoadImage(const std::string& pixels)
{
	std::istringstream s(pixels);
	Size size;
	std::string line;
	while (std::getline(s, line))
	{
		size.width = std::max(size.width, static_cast<int>(line.length()));
		++size.height;
	}

	Image img(size);

	s = std::istringstream(pixels);
	for (int y = 0; y < size.height; ++y)
	{
		if (!std::getline(s, line))
			break;

		int x = 0;
		for (char ch : line)
		{
			img.SetPixel({ x++, y }, ch);
		}
	}

	return img;
}
