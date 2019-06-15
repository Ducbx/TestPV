// copyConstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class Person
{
	string *_name;
	int _age;
public:
	Person() :_name(nullptr), _age(0){}
	~Person(){}
	Person(string name, int age)
	{
		this->_name = new string(name);
		this->_age = age;
	}

	Person(const Person &p)
	{
		this->_name = new string(*p._name);
		this->_age = p._age;
	}

	void ChangeInfo(string name, int age)
	{
		*(this->_name) = name;
		this->_age = age;
	}
	void Output()
	{
		cout << "\nName: " << *(this->_name) << ", Age: " << this->_age;
	}
};

class ReferenceCount
{
	int _count;
public:
	ReferenceCount() :_count(0){}
	void Increment()
	{
		++_count;
	}
	int Decrement()
	{
		return --_count;
	}
	int GetCount() const
	{
		return _count;
	}
};

class SmartPointer
{
private:
	Person *m_pObject;
	ReferenceCount *m_pReferenceCount;
public:
	//constructor
	SmartPointer() :m_pObject(nullptr), m_pReferenceCount(nullptr){}
	SmartPointer(Person *per)
	{
		m_pObject = per;
		m_pReferenceCount = new ReferenceCount();
		m_pReferenceCount->Increment();
		cout << "Created smart_ptr! Ref count is " << m_pReferenceCount->GetCount() << endl;
	}
	//Destructor
	virtual ~SmartPointer()
	{
		if (m_pReferenceCount)
		{
			int decrementCount = m_pReferenceCount->Decrement();
			cout << "Destroyed smart_ptr! Ref count is " << decrementCount << endl;
			if (decrementCount <= 0)
			{
				delete m_pReferenceCount;
				delete m_pObject;

				m_pReferenceCount = nullptr;
				m_pObject = nullptr;
			}
		}
	}
	//Copy constructor
	SmartPointer(const SmartPointer &other)
	{
		this->m_pObject = other.m_pObject;
		this->m_pReferenceCount = other.m_pReferenceCount;
		this->m_pReferenceCount->Increment();
		cout << "Copied smart_ptr! Ref count is "<< this->m_pReferenceCount->GetCount() << endl;
	}
	//Overloaded Assigment operator
	SmartPointer& operator= (const SmartPointer& other)
	{
		if (this != &other)
		{
			if (this->m_pReferenceCount && m_pReferenceCount->Decrement() == 0)
			{
				delete this->m_pReferenceCount;
				delete this->m_pObject;
			}
			this->m_pReferenceCount = other.m_pReferenceCount;
			this->m_pObject = other.m_pObject;
			this->m_pReferenceCount->Increment();
		}
		cout << "Assigning smart_ptr! Ref count is " << m_pReferenceCount->GetCount() << endl;
		return *this;
	}

	//Dereference operator
	Person& operator*()
	{
		return *this->m_pObject;
	}
	//Member Access operator
	Person* operator->()
	{
		return this->m_pObject;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	/*Person p1("duc", 28);
	p1.Output();

	Person p2 = p1;
	p2.Output();

	p1.ChangeInfo("Thuan", 29);
	p1.Output();
	p2.Output();*/

	SmartPointer personPtr(new Person("Duc", 28 )); 
	personPtr->ChangeInfo("Thuan", 27);
	(*personPtr).ChangeInfo("Nga", 26);
	SmartPointer hornettPointer(new Person("Cuong", 25)); 
	personPtr = hornettPointer; 
	
	system("pause");
	return 0;
}

