#include <iostream>
#include "bst.h"
#include "bst.cpp"
#include <windows.h> 
using namespace std;
int main()
{
	cout<<"--本程序基于BST实现了静态查找表的查找功能--"<<endl;
	cout<<"--下面开始验证--"<<endl;
	cout<<"--首先请构建一棵BST--"<<endl;
	cout<<"假定树中元素均为正整数，要求元素之间用空格间隔，以-1作为结束标志"<<endl;
	cout<<"并且您所输入的序列将按顺序插入到一棵BST中"<<endl; 
	cout<<"例如：27 32 3 2 4 -1"<<endl;
	cout<<"下面请输入您要构建的BST中的元素序列："<<endl;
	bst tree;
	int c;
	while(cin>>c)
	{
		if(c==-1) break;
		else
		{
			tree.insert(c);
		}
	}
	int k;
	while(1)
	{
		cout<<"请输入要查找的元素值(输入-1时停止查找)：";
		cin>>k;
		if(k==-1) break;
		else tree.find(k);
	}
	system("pause");
	return 0;
}
