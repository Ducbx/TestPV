// TestH.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int main()
{
	int h;
	do
	{
		cout << "\nNhap chieu cao h:";
		cin >> h;
	} while (h < 4 || h%2!=0);

	for (int i = 0; i <= h; i++)
	{
		for (int j = 0; j <= h / 2; j++)
		{
			if (j == 0 || j == h / 2 || i == h / 2)
			{
				cout << " * ";
			}
			else
			{
				cout << "   ";
			}
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}

