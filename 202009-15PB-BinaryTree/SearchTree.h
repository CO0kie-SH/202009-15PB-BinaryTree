#pragma once
#include <iostream>
using namespace std;

class SearchTree
{
public:
	SearchTree();
	~SearchTree();
	// ����ṹ��
	typedef struct _NODE
	{
		int data;
		//������������
		_NODE* left;
		_NODE* right;
		_NODE* parent;
	}NODE, * PNODE;
private:
	// ������ڵ�
	PNODE m_root = nullptr;
	unsigned int m_deep = 1;
	void insert(PNODE& node, int data, PNODE& parent);
	// �Ӷ�������ɾ��Ԫ��
	void erase(PNODE& node, int data);
	void print(PNODE& node, int w, char c);
	// ����ָ���������ڵ�
	int max(PNODE& node);
	void front(PNODE& node);	//ǰ�������������
	void middle(PNODE& node);	//��������������
	void back(PNODE& node,int& max);		//������������Ҹ�
public:
	void Insert(int data);
	// �ӿ�: ������ɾ��Ԫ��
	void erase(int data);
	void PrintByDeep();
	void Print();

	void Front();
	void Middle();
	void Back();
};

