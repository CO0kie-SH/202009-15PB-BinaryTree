// 202009-15PB-BinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
#include "SearchTree.h"
#include "CTbstree.h"

void 二叉查找树()
{
    SearchTree tree;
    tree.Insert(0x0F);
    tree.Insert(22);
    tree.Insert(11);
    tree.Print();
    tree.Insert(9);
    tree.Print();
    //层序遍历
    tree.PrintByDeep();
    //前序遍历 根左右
    tree.Front();	//前序遍历，根左右
    tree.Middle();	//中序遍历，左根右
    tree.Back();	//后序遍历，左右根
    tree.Insert(2);
    tree.Back();	//后序遍历，左右根
}

void 二叉查找树模板()
{
    CTbstree<long> tree;
    tree.Insert(0x0F);
    tree.Insert(22);
    tree.Insert(11);
    tree.Print();
    tree.Insert(9);
    tree.Print();
    //层序遍历
    tree.PrintByDeep();
    //前序遍历 根左右
    tree.Front();	//前序遍历，根左右
    tree.Middle();	//中序遍历，左根右
    tree.Back();	//后序遍历，左右根
    tree.Insert(2);
    tree.Back();	//后序遍历，左右根

}

int main()
{
    std::cout << "Hello World!\n";
    二叉查找树();
    二叉查找树模板();
}
