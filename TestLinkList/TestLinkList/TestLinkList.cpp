// TestLinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct People {
	string sur_name;
	string last_name;
	int age;
	string nationality;
	string job;

	struct People()
	{
		this->sur_name = "";
		this->last_name = "";
		this->age = 0;
		this->nationality = "";
		this->job = "";
	}

	struct People(string surName, string lastName, int age, string nati, string job)
	{
		this->sur_name = surName;
		this->last_name = lastName;
		this->age = age;
		this->nationality = nati;
		this->job = job;
	}

	void OutputInfo()
	{
		cout << "\t" << sur_name << "\t" << last_name << "\t" << age << "\t" << nationality << "\t" << job;
		cout << "\n";
	}
	
	bool operator== (const People& people) const
	{
		return (people.sur_name.compare(this->sur_name)==0 && people.last_name.compare(this->last_name)==0);
	}
};


template <class T>
struct Node
{
	T data;
	struct Node<T> *pNext;
	struct Node<T> *pPrev;

	static struct Node<T>* CreateNode(T value)
	{
		struct Node<T> *node = new Node<T>();
		node->data = value;
		node->pNext = NULL;
		node->pPrev = NULL;
		return node;
	}
	/*~Node()
	{
		if (std::is_pointer<T>::value)
		{
			delete data;
		}
	}*/
};

template <class T>
class CList
{
public:
	Node<T> *m_pHead;
	Node<T> *m_pTail;
public:
	CList();
	~CList();
	void AddHead(T data);
	void AddTail(T data);
	void AddRecordPAfterRecordQ(T p, T q);
	void DeleteHead();
	void DeleteTail();
	void DeleteRecord(T value);
	void ClearList();
};

template <class T>
CList<T>::CList()
{
	m_pHead = NULL;
	m_pTail = NULL;
}

template <class T>
CList<T>::~CList()
{
	ClearList();
}

template <class T>
void CList<T>::AddHead(T data)
{
	Node<T> *p = Node<T>::CreateNode(data);
	if (m_pHead == NULL)
	{
		m_pHead = p;
		m_pTail = p;
	}
	else
	{
		p->pNext = m_pHead;
		m_pHead->pPrev = p;
		m_pHead = p;
	}
}

template <class T>
void CList<T>::AddTail(T data)
{
	Node<T> *p = Node<T>::CreateNode(data);
	if (m_pHead == NULL)
	{
		m_pHead = p;
		m_pTail = p;
	}
	else
	{
		m_pTail->pNext = p;
		p->pPrev = m_pTail;
		m_pTail = p;
	}
}

template <class T>
void CList<T>::AddRecordPAfterRecordQ(T p, T q)
{
	Node<T> nodeP = Node<T>::CreateNode(p);
	for (Node<T> *node = m_pHead; node != NULL; node = node->pNext)
	{
		if (node->data == q)
		{
			Node<T> *nodeG = node->pNext;
			node->pNext = nodeP;
			nodeP->pNext = nodeG;
			nodeP->pPrev = node;
			nodeG->pPrev = nodeP;
			return;
		}
	}
}

template <class T>
void CList<T>::DeleteHead()
{
	if (m_pHead == NULL)
	{
		return;
	}
	Node<T> *p = m_pHead;
	if (m_pHead->pNext == NULL){
		m_pHead = NULL;
		m_pTail = NULL;
	}
	else {
		m_pHead->pNext->pPrev = NULL;
		m_pHead = m_pHead->pNext;
	}
	delete p;
}

template <class T>
void CList<T>::DeleteTail()
{
	if (m_pHead == NULL)
	{
		return;
	}
	Node<T> *p = m_pTail;
	if (m_pHead->pNext == NULL){
		m_pHead = NULL;
		m_pTail = NULL;
	}
	else
	{
		m_pTail->pPrev->pNext = NULL;
		m_pTail = m_pTail->pPrev;
	}
	delete p;
}

template <class T>
void CList<T>::DeleteRecord(T value)
{
	if (m_pHead == NULL)
	{
		return;
	}
	if (m_pHead->data == value)
	{
		DeleteHead();
		return;
	}
	if (m_pTail->data == value)
	{
		DeleteTail();
		return;
	}

	for (Node<T> *node = m_pHead->pNext; node->pNext != NULL; node = node->pNext)
	{
		if (node->data == value)
		{
			node->pPrev->pNext = node->pNext;
			node->pNext->pPrev = node->pPrev;
			delete node;
			return;
		}
	}

}

template <class T>
void CList<T>::ClearList()
{
	while (m_pHead != NULL)
	{
		DeleteHead();
	}
}


template <class T>
void InputListPeople(CList<T> &list, int peopleCount)
{
	for (int i = 0; i < peopleCount; i++)
	{
		string surName = "SurName_" + to_string(i);
		string lastName = "LastName_" + to_string(i);
		int age = i;
		string nationality = "Nationality_" + to_string(i);
		string job = "job_" + to_string(i);
		People* people = new People(surName, lastName, age, nationality, job);
		list.AddTail(*people);
	}
}

template <class T>
void Output(const CList<T>& list)
{
	cout << "\nOutput\n";
	for (Node<People> *p = list.m_pHead; p != NULL; p = p->pNext)
	{
		p->data.OutputInfo();
	}
}

template <class T>
void OutputInvert(const CList<T>& list)
{
	cout << "\nOutput Invert\n";
	for (Node<People> *p = list.m_pTail; p != NULL; p = p->pPrev)
	{
		p->data.OutputInfo();
	}
}


int main()
{
	CList<People> list;
	int peopleCount;
	cout << "Nhap so luong crecord: ";
	cin >> peopleCount;
	InputListPeople(list, peopleCount);

	Output(list);
	OutputInvert(list);
	
	string surName = "SurName_" + to_string(2);
	string lastName = "LastName_" + to_string(2);
	int age = 2;
	string nationality = "Nationality_" + to_string(2);
	string job = "job_" + to_string(2);
	People* people = new People(surName, lastName, age, nationality, job);

	list.DeleteRecord(*people);
	Output(list);
	
	system("pause");
	return 0;
}

