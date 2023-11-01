#pragma once
#include <string>
#include <filesystem>


/*
�����������
*/
class IImage
{
public:
	// ���������� ���� ������������ �������� ���������
	virtual std::filesystem::path GetPath()const = 0;
	// ������ ����������� � ��������
	virtual unsigned int GetWidth()const = 0;
	// ������ ����������� � ��������
	virtual unsigned int GetHeight()const = 0;
	// �������� ������ �����������
	virtual void Resize(unsigned int width, unsigned int height) = 0;
	virtual std::string GetInfo()const = 0;
	virtual ~IImage() = default;
};
