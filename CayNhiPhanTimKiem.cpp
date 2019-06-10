// CayNhiPhanTimKiem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int data;
	struct Node* pLeft;
	struct Node* pRight;

	static struct Node* CreateNode(int x)
	{
		struct Node *node = new Node();
		node->data = x;
		node->pLeft = NULL;
		node->pRight = NULL;
		return node;
	}
};
typedef struct Node NODE;

class BinaryTree
{
private:
	NODE *m_Tree;
public:
	BinaryTree();
	~BinaryTree();
	void AddNode(NODE* &tree, int x);
	void AddNode();
	void Output_LNR(NODE *tree);
	void Output_LNR();
	void Output_NLR(NODE *tree);
	void Output_NLR();
	void ClearTree(NODE *&tree);
	bool Search(int x);
	bool Search(NODE *tree,int x);
	void PrintNodeHave2ChildNode(NODE *tree);
	void PrintNodeHave2ChildNode();
	int FindMax(NODE *tree);
	int FindMax();
	void DeleteNode(NODE* &tree, int x);
	void DeleteNode(int x);
	void TimNodeTheMang(NODE *&x, NODE *&y);
};

BinaryTree::BinaryTree()
{
	m_Tree = NULL;
}

BinaryTree::~BinaryTree()
{
	ClearTree(m_Tree);
	m_Tree = NULL;
}

void BinaryTree::ClearTree(NODE* &tree)
{
	if (tree==NULL)
	{
		return;
	}
	else
	{
		ClearTree(tree->pLeft);
		ClearTree(tree->pRight);
		NODE* p = tree;
		delete p;
	}
}
void BinaryTree::Output_LNR()
{
	Output_LNR(m_Tree);
}

void BinaryTree::Output_LNR(NODE *tree)
{
	if (tree != NULL)
	{
		Output_LNR(tree->pLeft);
		cout << tree->data << "\t";
		Output_LNR(tree->pRight);
	}
}

void BinaryTree::Output_NLR()
{
	Output_NLR(m_Tree);
}

void BinaryTree::Output_NLR(NODE *tree)
{
	if (tree != NULL)
	{
		cout << tree->data << "\t";
		Output_NLR(tree->pLeft);
		Output_NLR(tree->pRight);
	}
}

void BinaryTree::AddNode()
{
	int count;
	cout << "\nNhap so luong phan tu: ";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int x;
		cout << "\nNhap du lieu: ";
		cin >> x;
		AddNode(m_Tree, x);
	}
}

void BinaryTree::AddNode(NODE* &tree, int x)
{
	if (tree == NULL)
	{
		NODE *p = NODE::CreateNode(x);
		tree = p;
	}
	else
	{
		if (x > tree->data)
		{
			AddNode(tree->pRight, x);
		}
		else
		{
			AddNode(tree->pLeft, x);
		}
	}
}

bool BinaryTree::Search(int x)
{
	return Search(m_Tree, x);
}

bool BinaryTree::Search(NODE *tree, int x)
{
	if (tree == NULL)
	{
		return false;
	}
	else
	{
		if (x > tree->data)
		{
			Search(tree->pRight,x);
		}
		else if (x<tree->data)
		{
			Search(tree->pLeft, x);
		}
		else
		{
			return true;
		}
	}
}

void BinaryTree::PrintNodeHave2ChildNode(NODE *tree)
{
	if (tree != NULL)
	{
		if (tree->pLeft != NULL && tree->pRight != NULL)
		{
			cout << tree->data << "\t";
		}
		PrintNodeHave2ChildNode(tree->pLeft);
		PrintNodeHave2ChildNode(tree->pRight);
	}
}

void BinaryTree::PrintNodeHave2ChildNode()
{
	PrintNodeHave2ChildNode(m_Tree);
}

int BinaryTree::FindMax(NODE *tree)
{
	if (tree->pLeft==NULL && tree->pRight==NULL)
	{
		return tree->data;
	}
	return FindMax(tree->pRight);
}

int BinaryTree::FindMax()
{
	return FindMax(m_Tree);
}

void BinaryTree::DeleteNode(NODE* &tree, int x)
{
	if (tree == NULL)
	{
		return;
	}
	if (x < tree->data)
	{
		DeleteNode(tree->pLeft, x);
	}
	else if (x>tree->data)
	{
		DeleteNode(tree->pRight, x);
	}
	else
	{
		NODE *p = tree;
		if (tree->pLeft == NULL)
		{
			tree = tree->pRight;
		}
		else if (tree->pRight == NULL)
		{
			tree = tree->pLeft;
		}
		else
		{
			NODE *q = tree->pRight; //node q the mang
			//Tim node Trai nhat cua cay con Phai
			//if (q->pLeft != NULL)
			//{
			//	TimNodeTheMang(p, q->pLeft);
			//}
			//else
			//{
			//	p->data = q->data;
			//	p = q;
			//	q = q->pRight; //NULL
			//}
			TimNodeTheMang(p, q);
		}
		delete p;
	}
}

void BinaryTree::DeleteNode(int x)
{
	DeleteNode(m_Tree,x);
}

void BinaryTree::TimNodeTheMang(NODE *&x, NODE *&y) //Y = tree->pRight;
{
	if (y->pLeft != NULL)
	{
		TimNodeTheMang(x, y->pLeft);
	}
	else
	{
		x->data = y->data;
		x = y;
		y = y->pRight; //NULL
	}
}

int main()
{
	BinaryTree tree;
	tree.AddNode();

	tree.Output_LNR();
	cout << endl;
	tree.Output_NLR();

	/*int x;
	cout << "\nNhap so can tim: ";
	cin >> x;
	if (tree.Search(x))
	{
		cout << "\nTim thay";
	}
	else
	{
		cout << "\nKhong Tim thay";
	}
	cout << "\nNode co 2 con: \n";
	tree.PrintNodeHave2ChildNode();
	cout << "\n" << tree.FindMax();*/
	int x;
	cout << "\nNhap so can xoa: ";
	cin >> x;
	tree.DeleteNode(x);
	tree.Output_NLR();

	system("pause");
	return 0;
}

