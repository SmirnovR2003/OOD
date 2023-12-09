#include <iostream>
#include <string>
#include <map>
#include <functional>

#include "IInputStream.h"
#include "CFileInputStream.h"
#include "IOutputStream.h"
#include "CFileOutputStream.h"
#include "CCrypt.h"
#include "CDecrypt.h"
#include "CCompress.h"
#include "CDecompress.h"

using namespace std;

unique_ptr<IInputStream> AddDecryptTurn(unique_ptr<IInputStream>&& stream, int key)
{
	return make_unique<CDecrypt>(move(stream), key);
}

unique_ptr<IOutputStream> AddEncryptTurn(unique_ptr<IOutputStream>&& stream, int key)
{
	return make_unique<CCrypt>(move(stream), key);
}

unique_ptr<IInputStream> AddDecompressTurn(unique_ptr<IInputStream>&& stream)
{
	return make_unique<CDecompress>(move(stream));
}

unique_ptr<IOutputStream> AddCompressTurn(unique_ptr<IOutputStream>&& stream)
{
	return make_unique<CCompress>(move(stream));
}



int main(int argc, char* argv[])
{
	unique_ptr<IInputStream> inFilePtr = make_unique<CFileInputStream>(CFileInputStream(argv[argc-2]));

	unique_ptr<IOutputStream> outFilePtr = make_unique<CFileOutputStream>(CFileOutputStream(argv[argc-1]));

	for (int i = 1; i < argc-2; i++)
	{
		if (strcmp(argv[i], "--encrypt") == 0)
		{
			auto newOutFilePtr = AddEncryptTurn(move(outFilePtr), atoi(argv[i + 1]));
			outFilePtr.swap(move(newOutFilePtr));
			i++;
		}
		else if (strcmp(argv[i], "--decrypt") == 0)
		{
			auto newInFilePtr = AddDecryptTurn(move(inFilePtr), atoi(argv[i + 1]));
			inFilePtr.swap(move(newInFilePtr));
			i++;
		}
		else if(strcmp(argv[i], "--compress") == 0)
		{
			auto newOutFilePtr = AddCompressTurn(move(outFilePtr));
			outFilePtr.swap(move(newOutFilePtr));
		}
		else if (strcmp(argv[i], "--decompress") == 0)
		{
			auto newInFilePtr = AddDecompressTurn(move(inFilePtr));
			inFilePtr.swap(move(newInFilePtr));
		}
		else
		{
			cout << argv[i] << " is invalid command on number " << i << endl;
		}
	}

	
	uint8_t buf;
	while (!inFilePtr->IsEOF())
	{
		outFilePtr->WriteByte(inFilePtr->ReadByte());
	}
	inFilePtr->Close();
	outFilePtr->Close();
	cout << "all ok\n";
	return 0;
}