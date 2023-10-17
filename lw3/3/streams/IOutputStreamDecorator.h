#pragma once
#include "IOutputStream.h"

// и ена фалов должны соответствоть содержимому
class COutputStreamDecorator :
    public IOutputStream
{
public:

	// «акрывает поток. ќперации над ним после этого должны выбрасывать исключение logic_error
	void Close()override
	{
		m_outputStream->Close();
	}


protected:
	COutputStreamDecorator(IOutputStreamPtr&& outputStream)
		: m_outputStream(move(outputStream))
	{
	}


	void WriteDecoratedByte(uint8_t data)
	{
		m_outputStream->WriteByte(data);
	}
private:
	IOutputStreamPtr m_outputStream;
};

