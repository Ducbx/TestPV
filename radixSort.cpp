// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int getMax(int *a, int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	return max;
}

void countSort(int *a, int n, int exp)
{
	int *temp = new int[n];
	int count[10] = { 0 };

	for (int i = 0; i < n; i++)
	{
		count[(a[i] / exp) % 10]++;
	}

	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i>= 0; i--)
	{
		temp[count[(a[i] / exp) % 10]-1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = temp[i];
	}

	delete[] temp;
}

void radixSort(int *a, int n)
{
	int max = getMax(a,n);
	int exp = 1;
	while (max/exp > 0)
	{
		countSort(a, n, exp);
		exp = exp * 10;
	}
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	radixSort(arr, n);
	print(arr, n);

	system("pause");
	return 0;
}

