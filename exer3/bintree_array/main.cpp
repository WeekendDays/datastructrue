#include <iostream>
#include<iomanip>
#include "bintree.h"
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int main() 
{
	cout<<"��ʾ��"<<endl
    <<"���ַ�����ʽ����Ҫ�����Ķ�����ʱ������α�����˳�����룬���еĿսڵ��ԡ�/������"<<endl
	<<"ע�⣡"<<endl
	<<"����Ҫ��ʾ�����һ��Ҷ�ӽ�����һ���������ָ��"
	<<"����abc//de////f/////////////"<<endl
	<<"�����룺"; 
	BinTree t;
	string str;
	cin>>str;
	int rt=0;
	t.init();
	t.createTree(str);
	cout<<"�ж����Ƿ��ǿ�����";
	if(t.BiTreeEmpty(rt)==true) 
	cout<<"������һ�ſ���"<<endl;
	else
	{
		cout<<"���벻�ǿ���"<<endl;
		cout<<"��α�����";
		t.LevelOrderTraverse(rt);
		cout<<endl<<endl;
	    cout<<"ǰ�������"; 
	    t.preorder(rt);
	    cout<<endl<<endl;
	    cout<<"���������";
        t.Inorder(rt); 
        cout<<endl<<endl;
        cout<<"���������";
	    t.postorder(rt);
	    cout<<endl<<endl; 
	} 
	cout<<"���ĸ߶ȣ�" <<t.BiTreeDepth(rt)<<endl;
	cout<<"���Ľ��ĸ�����"<<t.count(rt)<<endl; 
	system("pause");
	return 0;
}
