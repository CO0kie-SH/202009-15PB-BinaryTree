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
void T16()
{
    SearchTree tree;
    tree.Insert(34);
    tree.Insert(76);
    tree.Insert(45);
    tree.Insert(18);
    tree.Insert(26);
    tree.Insert(54);
    tree.Insert(92);
    tree.PrintByDeep();
}

void T17()
{
    SearchTree tree;
    tree.Insert(54);
    tree.Insert(28);
    tree.Insert(16);
    tree.Insert(34);
    tree.Insert(73);
    tree.Insert(62);
    tree.Insert(95);
    tree.Insert(60);
    tree.Insert(26);
    tree.Insert(43);
    tree.PrintByDeep();
}
int main()
{
    std::cout << "Hello World!\n";
    二叉查找树();
    二叉查找树模板();
    T16();
    T17();
}
