// DaoTuTrongChuoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string strInput;
	string strOut = "";
	cout << "\nNhap chuoi : ";
	getline(cin, strInput);
	int iSize = strInput.size();
	int i, j = iSize - 1;

	for (i = iSize - 1; i >= 0; i--)
	{
		if (strInput[i] == ' ')
		{
			for (int pos = i + 1; pos <= j; pos++)
			{
				strOut += strInput[pos];
			}
			j = i - 1;
			strOut += strInput[i];
		}
		if (i == 0)
		{
			for (int pos = i; pos <= j; pos++)
			{
				strOut += strInput[pos];
			}
		}
	}

	cout << "\n" << strOut << endl;

	system("pause");
	return 0;
}

