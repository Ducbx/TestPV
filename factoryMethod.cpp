// Test.cpp : Defines the entry point for the console application.
//
//Facory method
#include "stdafx.h"
#include <iostream>
using namespace std;


class CShape
{
public:
	virtual void draw() = 0;
};

class CCircle : public CShape
{
public:
	virtual void draw()
	{
		cout << "\nDraw circle";
	}
};

class CSquare : public CShape
{
public:
	virtual void draw()
	{
		cout << "\nDraw square";
	}
};

enum shape
{
	circle = 0,
	square
};

class CShapeFactory
{
public:
	CShape* getShape(int type)
	{
		if (type == shape::circle)
		{
			return new CCircle();
		}
		if (type == shape::square)
		{
			return new CSquare();
		}
		return NULL;
	}
};

int main()
{
	CShapeFactory *shapeFactory = new CShapeFactory();
	CShape *circle = shapeFactory->getShape(shape::circle);
	circle->draw();

	CShape *square = shapeFactory->getShape(shape::square);
	square->draw();

	system("pause");
	return 0;
}