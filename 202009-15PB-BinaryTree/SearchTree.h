#pragma once
#include <iostream>
using namespace std;

class SearchTree
{
public:
	SearchTree();
	~SearchTree();
	// 定义结构体
	typedef struct _NODE
	{
		int data;
		//定义左右子树
		_NODE* left;
		_NODE* right;
		_NODE* parent;
	}NODE, * PNODE;
private:
	// 定义根节点
	PNODE m_root = nullptr;
	unsigned int m_deep = 1;
	void insert(PNODE& node, int data, PNODE& parent);
	// 从二叉树内删除元素
	void erase(PNODE& node, int data);
	void print(PNODE& node, int w, char c);
	// 查找指定树的最大节点
	int max(PNODE& node);
	void front(PNODE& node);	//前序遍历，根左右
	void middle(PNODE& node);	//中序遍历，左根右
	void back(PNODE& node,int& max);		//后序遍历，左右根
public:
	void Insert(int data);
	// 接口: 从树中删除元素
	void erase(int data);
	void PrintByDeep();
	void Print();

	void Front();
	void Middle();
	void Back();
};

