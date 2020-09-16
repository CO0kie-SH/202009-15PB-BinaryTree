#include "SearchTree.h"
#include <vector>
#include <cmath>


SearchTree::SearchTree()
{
}

SearchTree::~SearchTree()
{
}

#pragma region 对内函数
// 内部插入函数
void SearchTree::insert(PNODE& node, int data)
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

void SearchTree::erase(PNODE& node, int data)
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

void SearchTree::print(PNODE& node, int w, char c)
{
	if (node != nullptr)
	{
		print(node->right, w + 4, '/');
		printf_s("%*s%c%02d\n", w, " ", c, node->data);
		print(node->left, w + 4, '\\');
	}
}

int SearchTree::max(PNODE& node)
{
	while (node->right)
		node = node->right;
	return node->data;
}

void SearchTree::front(PNODE& node)
{
	if (node) {
		printf_s("%d ", node->data);
		front(node->left);
		front(node->right);
	}
}

void SearchTree::middle(PNODE& node)
{
	if (node) {
		middle(node->left);
		printf_s("%d ", node->data);
		middle(node->right);
	}
}

void SearchTree::back(PNODE& node,int& max)
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

// 插入接口
void SearchTree::Insert(int data)
{
	insert(m_root, data);
}

// 接口: 从树中删除元素
void SearchTree::erase(int data)
{
	erase(m_root, data);
}

void SearchTree::PrintByDeep()
{
	vector<PNODE> allptr = {m_root,m_root->left,m_root->right };
	unsigned int deep = 1, index = 1, rig = 0;
	bool ret = false;
	while (deep<5)
	{
		ret = true;
		rig = index + pow(2, deep);
		printf_s("第%d层 %d~%d\t", deep+1, index, rig-1);
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

//打印接口
void SearchTree::Print()
{
	print(m_root, 0, '*');
	cout << "——————"<<endl;
}
void SearchTree::Front()
{
	front(m_root);
	cout << "\n——————" << endl;
}
void SearchTree::Middle()
{
	middle(m_root);
	cout << "\n——————" << endl;
}
void SearchTree::Back()
{
	int max = 1;
	back(m_root, max);
	cout << "\n——————最大层=" << max - 1 << endl;
}
#pragma endregion

