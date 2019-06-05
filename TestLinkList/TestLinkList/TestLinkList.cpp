// TestLinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct People {
	string surname;
	string last_name;
	int age;
	string nationality;
	string job;
};
typedef struct People PEOPLE;

template <class Data>;
struct Node
{
	int iData;
	struct Node *pNext;
	struct Node *pPrev;
};
typedef struct Node NODE;

struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

void InitList(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* GetNode(int iValue)
{
	NODE *node = new NODE();
	if (node == NULL)
	{
		return NULL;
	}
	node->iData = iValue;
	node->pNext = NULL;
	node->pPrev = NULL;
}

void AddHead(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pHead = p;
	}
}

void AddTail(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}

void Input(LIST &l, int n)
{
	InitList(l);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "\nNhap data:";
		cin >> x;
		NODE *p = GetNode(x);
		AddTail(l, p);
		//AddHead(l, p);
	}
}

void Output(LIST l)
{
	for (NODE *p = l.pTail; p != NULL; p = p->pPrev)
	//for (NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << "\t" << p->iData;
	}
}



void AddNodePAfterNodeQ(LIST &l, NODE *p, NODE *q)
{
	for (NODE *node = l.pHead; node != NULL; node = node->pNext)
	{
		if (node->iData == q->iData)
		{
			NODE *g = node->pNext;			//g==q
			node->pNext = p;
			p->pNext = g;
			p->pPrev = node;
			g->pPrev = p;
			return;
		}
	}
}

void DeleteHead(LIST &l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	NODE *p = l.pHead;
	if (l.pHead->pNext == NULL){
		l.pHead = NULL;
		l.pTail = NULL;
	}
	else {
		l.pHead->pNext->pPrev = NULL;
		l.pHead = l.pHead->pNext;
	}
	delete p;
}

void DeleteTail(LIST &l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	NODE *p = l.pTail;
	if (l.pHead->pNext == NULL){
		l.pHead = NULL;
		l.pTail = NULL;
	}
	else
	{
		l.pTail->pPrev->pNext = NULL;
		l.pTail = l.pTail->pPrev;
	}
	delete p;
}

void DeleteRecord(LIST &l, int iValue)
{
	if (l.pHead == NULL)
	{
		return;
	}
	if (l.pHead->iData == iValue)
	{
		DeleteHead(l);
		return;
	}
	if (l.pTail->iData == iValue)
	{
		DeleteTail(l);
		return;
	}

	for (NODE *node = l.pHead->pNext; node->pNext != NULL; node = node->pNext)
	{
		if (node->iData == iValue)
		{
			node->pPrev->pNext = node->pNext;
			node->pNext->pPrev = node->pPrev;
			delete node;
			return;
		}
	}

}

void ClearList(LIST &l)
{
	while (l.pHead != NULL)
	{
		DeleteHead(l);
	}
}

int main()
{
	LIST l;
	int n;
	cout << "\nNhap so phan tu: ";
	cin >> n;
	Input(l, n);
	Output(l);

	/*int q;
	cout << "\nNhap q:";
	cin >> q;
	NODE *Q = GetNode(q);
	int p;
	cout << "\nNhap p:";
	cin >> p;
	NODE *P = GetNode(p);*/
	cout << "\n";
	//AddNodePAfterNodeQ(l, P, Q);
	//DeleteTail(l);
	//DeleteHead(l);
	//Output(l);


	int value;
	cout << "\nNhap value: ";
	cin >> value;
	DeleteRecord(l, value);

	//ClearList(l);
	Output(l);
	system("pause");
	return 0;
}

