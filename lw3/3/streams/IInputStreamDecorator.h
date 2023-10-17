#pragma once
#include "IInputStream.h"
//сделать так чтобы декоратор не знал об конкретных декораторах
class CInputStreamDecorator :
    public IInputStream
{
public:
	// Возвращает признак достижения конца данных потока
	// Выбрасывает исключение std::ios_base::failuer в случае ошибки
	bool IsEOF() const override
	{
		return m_inputStream.get()->IsEOF();
	}

	// Считывает байт из потока.
	// Выбрасывает исключение std::ios_base::failure в случае ошибки
	uint8_t ReadByte() override
	{
		return m_inputStream->ReadByte();
	}

	// Считывает из потока блок данных размером size байт, записывая его в память
	// по адресу dstBuffer
	// Возвращает количество реально прочитанных байт. Выбрасывает исключение в случае ошибки
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override
	{

		return m_inputStream.get()->ReadBlock(dstBuffer, size);
	}

	// Закрывает поток. Операции над ним после этого должны выбрасывать исключение logic_error
	void Close()override
	{
		m_inputStream.get()->Close();
	}


protected:
	CInputStreamDecorator(IInputStreamPtr&& inputStream)
		: m_inputStream(std::move(inputStream))
	{
	}

	void ReadOneByte(uint8_t& byte)
	{
		byte = m_inputStream->ReadByte();
	}

	void ReadTwoBytes(uint8_t& byte1, uint8_t& byte2)
	{
		byte1 = m_inputStream->ReadByte();
		byte2 = m_inputStream->ReadByte();
	}
private:
	IInputStreamPtr m_inputStream;
};

