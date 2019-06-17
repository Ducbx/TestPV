// Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

void convert2Binary(int n)
{
	if (n == 0) return;
	convert2Binary(n/2);

	cout << n % 2;
}

int recursion(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	return recursion(n - 1) + recursion(n - 2);
}

int notRecursion(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	int p1 = 1;
	int p2 = 2;
	int pn = 0;
	for (int i = 3; i <= n; i++)
	{
		pn = p1 + p2;
		p1 = p2;
		p2 = pn;
	}
	return pn;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 40;
	clock_t start1 = clock();
	for (int i = 0; i < 10; i++)
	cout << "\nNot recursion: n = " << n << "-> " << notRecursion(n);
	clock_t end1 = clock();
	cout << "\n Time = " << (double)(end1 - start1) / CLOCKS_PER_SEC;

	clock_t start2 = clock();
	for (int i = 0; i < 10; i++)
	cout << "\nRecursion: n = " << n << "-> " << recursion(n);
	clock_t end2 = clock();
	cout << "\n Time = " << (double)(end2 - start2) / CLOCKS_PER_SEC;


	cout << endl;
	system("pause");
	return 0;
}

