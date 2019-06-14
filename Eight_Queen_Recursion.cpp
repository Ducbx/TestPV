// Eight_Queen_Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int a[8] = { 0 };
void Output(int n)
{
	for (int i = 1; i <=n; i++)
	{
		cout << "  " << a[i];
	}
	cout << endl;
}

bool Check(int x, int y)
{
	for (int i = 1; i < x; i++)
	{
		if (a[i] == y || abs(x - i) == abs(y - a[i]))
		{
			return false;
		}
	}
	return true;
}

void Try(int i, int n)
{
	for (int j = 1; j <= n; j++)
	{
		if (Check(i, j))
		{
			a[i] = j;
			if (i == n)
			{
				Output(n);
			}
			Try(i + 1, n);
		}
	}
}

int main()
{
	int n = 8;
	Try(1, n);
	system("pause");
	return 0;
}

