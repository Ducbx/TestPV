// TamGiacSao.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int h;
	cout << "\nNhap h:";
	cin >> h;

	//Tam giac can
	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < 2*h; j++)
		{
			if((h-1-i)<=j && (h-1+i)>=j)
			{
				cout << " * ";
			}
			else
			{
				cout << "   ";
			}
		}
		cout << "\n";
	}*/

	//Tam giac vuong goc L (1)
	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < h; j++) //for(J=0; j<=i; j++)==> cout<<"*";
		{
			if (j <= i)
			{
				cout << " * ";
			}
		}
		cout << "\n";
	}*/

	//Tam giac vuong goc (2) (kim dong ho)
	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (j <= h - 1 - i)
			{
				cout << " * ";
			}
		}
		cout << endl;
	}*/
	
	//Tam giac vuong goc (3)
	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (j >= i)
			{
				cout << " * ";
			}
			else
			{
				cout << "   ";
			}
		}
		cout << "\n";
	}*/

	//Tam giac vuong goc (4)
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (j >= h - 1 - i)
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

