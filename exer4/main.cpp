#include <iostream>
#include "bst.h"
#include "bst.cpp"
#include <windows.h> 
using namespace std;
int main()
{
	cout<<"--���������BSTʵ���˾�̬���ұ�Ĳ��ҹ���--"<<endl;
	cout<<"--���濪ʼ��֤--"<<endl;
	cout<<"--�����빹��һ��BST--"<<endl;
	cout<<"�ٶ�����Ԫ�ؾ�Ϊ��������Ҫ��Ԫ��֮���ÿո�������-1��Ϊ������־"<<endl;
	cout<<"����������������н���˳����뵽һ��BST��"<<endl; 
	cout<<"���磺27 32 3 2 4 -1"<<endl;
	cout<<"������������Ҫ������BST�е�Ԫ�����У�"<<endl;
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
		cout<<"������Ҫ���ҵ�Ԫ��ֵ(����-1ʱֹͣ����)��";
		cin>>k;
		if(k==-1) break;
		else tree.find(k);
	}
	system("pause");
	return 0;
}
