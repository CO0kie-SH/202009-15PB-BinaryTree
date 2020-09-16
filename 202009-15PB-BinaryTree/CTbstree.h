#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <cmath>


template <class T>
class CTbstree
{
public:
	// ����ṹ��
	typedef struct _NODE
	{
		T data;
		//������������
		_NODE* left;
		_NODE* right;
	}NODE, * PNODE;
private:
	// ������ڵ�
	PNODE m_root = nullptr;
	unsigned int m_deep = 1;
	void insert(PNODE& node, T data);
	// �Ӷ�������ɾ��Ԫ��
	void erase(PNODE& node, T data);
	void print(PNODE& node, int w, char c);

	// ����ָ��������С�ڵ�
	//int min(PNODE& node);

	// ����ָ���������ڵ�
	int max(PNODE& node);
	void front(PNODE& node);	//ǰ�������������
	void middle(PNODE& node);	//��������������
	void back(PNODE& node, int& max);		//������������Ҹ�
public:
	void Insert(T data);
	// �ӿ�: ������ɾ��Ԫ��
	void erase(T data);
	void PrintByDeep();
	void Print();

	void Front();
	void Middle();
	void Back();
};


#pragma region ���ں���

template <class T>
// �ڲ����뺯��
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
		//������ֵͬ�����
		return;
	}
}

template <class T>
void CTbstree<T>::erase(PNODE& node, T data)
{
	//ѭ��Ϊ��ʱ����
	if (node == nullptr) {

	}
	//���Ҳ�ѯ
	else if (data > node->data)
	{
		erase(node->right, data);
	}
	//�����ѯ
	else if (data < node->data)
	{
		erase(node->right, data);
	}
	//ɾ���ڵ�
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

#pragma region ����ӿ�
template <class T>
// ����ӿ�
void CTbstree<T>::Insert(T data)
{
	insert(m_root, data);
}

template <class T>
// �ӿ�: ������ɾ��Ԫ��
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
		printf_s("��%d�� %d~%d\t", deep + 1, index, rig - 1);
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
	cout << "������������" << endl;
}

template <class T>
//��ӡ�ӿ�
void CTbstree<T>::Print()
{
	print(m_root, 0, '*');
	cout << "������������" << endl;
}

template <class T>
void CTbstree<T>::Front()
{
	front(m_root);
	cout << "\n������������" << endl;
}

template <class T>
void CTbstree<T>::Middle()
{
	middle(m_root);
	cout << "\n������������" << endl;
}

template <class T>
void CTbstree<T>::Back()
{
	int max = 0;
	back(m_root, max);
	cout << "\n����������������=" << max << endl;
}
#pragma endregion