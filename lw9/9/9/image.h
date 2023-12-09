#pragma once
#include <iosfwd>
#include <iostream>
#include <string>
#include <vector>
#include "tile.h"
#include "CoW.h"

#include "geom.h"

class Image
{
public:
	/**
     * Конструирует изображение заданного размера. Если размеры не являются положительными,
     * выбрасывает исключение std::out_of_range.
     */
	explicit Image(Size size, uint32_t color = 0);

	// Возвращает размер изображения в пикселях.
	Size GetSize() const noexcept;

	/**
     * Возвращает «цвет» пикселя в указанных координатах.Если координаты выходят за пределы
     * изображения, возвращает «пробел».
     */
    uint32_t GetPixel(Point p) const noexcept;

	/**
     * Задаёт «цвет» пикселя в указанных координатах. Если координаты выходят за пределы изображения
     * действие игнорируется.
     */
	void SetPixel(Point p, uint32_t color);

    ~Image()
    {
        std::cout << m_image[0][0]->GetInstanceCount() << std::endl;
        
    }
private:
    Size m_size;
    std::vector<std::vector<CoW<Tile>>> m_image;
};

/**
 * Выводит в поток out изображение в виде символов.
 */
//вынести в отдельный класс
void Print(const Image& img, std::ostream& out);

/**
 * Загружает изображение из pixels. Линии изображения разделяются символами \n.
 * Размеры картинки определяются по количеству переводов строки и самой длинной линии.
 */
 //вынести в отдельный класс
Image LoadImage(const std::string& pixels);
