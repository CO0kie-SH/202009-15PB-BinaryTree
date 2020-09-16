#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <cmath>


template <class T>
class CTbstree
{
public:
	// 定义结构体
	typedef struct _NODE
	{
		T data;
		//定义左右子树
		_NODE* left;
		_NODE* right;
	}NODE, * PNODE;
private:
	// 定义根节点
	PNODE m_root = nullptr;
	unsigned int m_deep = 1;
	void insert(PNODE& node, T data);
	// 从二叉树内删除元素
	void erase(PNODE& node, T data);
	void print(PNODE& node, int w, char c);

	// 查找指定树的最小节点
	//int min(PNODE& node);

	// 查找指定树的最大节点
	int max(PNODE& node);
	void front(PNODE& node);	//前序遍历，根左右
	void middle(PNODE& node);	//中序遍历，左根右
	void back(PNODE& node, int& max);		//后序遍历，左右根
public:
	void Insert(T data);
	// 接口: 从树中删除元素
	void erase(T data);
	void PrintByDeep();
	void Print();

	void Front();
	void Middle();
	void Back();
};


#pragma region 对内函数

template <class T>
// 内部插入函数
void CTbstree<T>::insert(PNODE& node, T data)
{
	if (node == nullptr) {
		node = (PNODE)new NODE{ data,nullptr,nullptr };
		if (!node) return;
	}
	else if (data < node->data)
	{
		insert(node->left, data);
	}
	else if (data > node->data)
	{
		insert(node->right, data);
	}
	else {
		//处理相同值的情况
		return;
	}
}

template <class T>
void CTbstree<T>::erase(PNODE& node, T data)
{
	//循环为空时弹出
	if (node == nullptr) {

	}
	//向右查询
	else if (data > node->data)
	{
		erase(node->right, data);
	}
	//向左查询
	else if (data < node->data)
	{
		erase(node->right, data);
	}
	//删除节点
	else
	{
		if (node->left && node->right) {
			int nm = max(node->left);
			node->data = nm;
			erase(node->left, nm);
		}
		else
		{
			PNODE temp = node;
			if (node->left) node = node->left;
			else if (node->right) node = node->right;
			else node = nullptr;
			delete temp;
		}
	}
}
template <class T>
void CTbstree<T>::print(PNODE& node, int w, char c)
{
	if (node != nullptr)
	{
		print(node->right, w + 4, '/');
		printf_s("%*s%c%02d\n", w, " ", c, node->data);
		print(node->left, w + 4, '\\');
	}
}
template <class T>
int CTbstree<T>::max(PNODE& node)
{
	while (node->right)
		node = node->right;
	return node->data;
}

template <class T>
void CTbstree<T>::front(PNODE& node)
{
	if (node) {
		printf_s("%d ", node->data);
		front(node->left);
		front(node->right);
	}
}

template <class T>
void CTbstree<T>::middle(PNODE& node)
{
	if (node) {
		middle(node->left);
		printf_s("%d ", node->data);
		middle(node->right);
	}
}
template <class T>
void CTbstree<T>::back(PNODE& node, int& max)
{
	if (node) {
		if (node->left) ++max;
		if (node->right) ++max;
		back(node->left, max);
		back(node->right, max);
		printf_s("%d ", node->data);
	}
}

#pragma endregion

#pragma region 对外接口
template <class T>
// 插入接口
void CTbstree<T>::Insert(T data)
{
	insert(m_root, data);
}

template <class T>
// 接口: 从树中删除元素
void CTbstree<T>::erase(T data)
{
	erase(m_root, data);
}

template <class T>
void CTbstree<T>::PrintByDeep()
{
	vector<PNODE> allptr = { m_root,m_root->left,m_root->right };
	unsigned int deep = 1, index = 1, rig = 0;
	bool ret = false;
	while (deep < 5)
	{
		ret = true;
		rig = index + (int)pow(2, deep);
		printf_s("第%d层 %d~%d\t", deep + 1, index, rig - 1);
		for (unsigned int i = index; i < rig; i++)
		{
			printf_s("[%d]", i);
			if (allptr[i]) {
				cout << allptr[i]->data << '\t';
				if (!allptr[i]->left)allptr.push_back(nullptr);
				else {
					ret = false;
					allptr.push_back(allptr[i]->left);
				}
				if (!allptr[i]->right)allptr.push_back(nullptr);
				else {
					ret = false;
					allptr.push_back(allptr[i]->right);
				}
			}
			else {
				cout << "NULL\t";
				allptr.push_back(nullptr);
				allptr.push_back(nullptr);
			}
		}
		cout << endl;
		if (ret) break;
		++deep;
		index = rig;
	}
	cout << "——————" << endl;
}

template <class T>
//打印接口
void CTbstree<T>::Print()
{
	print(m_root, 0, '*');
	cout << "——————" << endl;
}

template <class T>
void CTbstree<T>::Front()
{
	front(m_root);
	cout << "\n——————" << endl;
}

template <class T>
void CTbstree<T>::Middle()
{
	middle(m_root);
	cout << "\n——————" << endl;
}

template <class T>
void CTbstree<T>::Back()
{
	int max = 0;
	back(m_root, max);
	cout << "\n——————最大层=" << max << endl;
}
#pragma endregion