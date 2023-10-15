#include <cstdint>
#include <iostream>
#include <string>
#include "CFileInputStream.h"

using namespace std;


int main()
{
	CFileInputStream file("in.txt");
	uint8_t* buf = new uint8_t;

	while (!file.IsEOF())
	{
		cout << file.ReadByte();
	}
	return 0;
}