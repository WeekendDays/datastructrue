#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include"BiNode.h"
#include"BinTree.cpp"
#include<windows.h>
using namespace std;

typedef char E;
char c[50];
int count=0;
string s;
BiNode*r;
BinTree T;
//����
BiNode*CreateBiTree(char ch){
    BiNode* rt;
	if(ch=='/')  rt=NULL;
	else{
	    rt=new BiNode;
		rt->setElement(ch);
		ch=c[++count];
		rt->setLeft(CreateBiTree(ch));
		ch=c[++count];
		rt->setRight(CreateBiTree(ch));}
	//���ø��ڵ�
	T.setRoot(rt);
    return rt;
}
int main()
{
    char ch;
	int depth;
	int num;
	cout<<"��ʾ��"<<endl
    <<"���ַ�����ʽ����Ҫ�����Ķ�����ʱ����ǰ�������˳�����룬���еĿսڵ��ԡ�/������"<<endl
	<<"ע�⣡"
	<<"ÿһ��Ҷ�ӽ��ҲҪ����������ս�㣬��/����ս��"
	<<"����ab/d//ce//f//"<<endl;
    cin>>s;
    strcpy(c,s.c_str());
    r=CreateBiTree(c[0]);
    cout<<"�ж����Ƿ��ǿ�����";
    if(T.BiTreeEmpty(r))
    {
    	cout<<"�������ǿ���"<<endl;
    	cout<<"��α�����";
		T.LevelOrderTraverse(r);
		cout<<endl;
		cout<<"ǰ�������";
		T.preorder(r);
		cout<<endl;
		cout<<"���������";
		T.Inorder(r);
		cout<<endl;
		cout<<"���������";
		T.postorder(r);
		cout<<endl;
}
    else cout<<"������һ�ÿ���"<<endl;
    cout<<"���ĸ߶ȣ�";
    depth=T.BiTreeDepth(r);
    cout<<depth<<endl;
    cout<<"������ȣ�";
    if (T.BiTreeEmpty(r))
	cout<<depth-1<<endl;
	else cout<<depth<<endl; 
    cout<<"���Ľ�������";
    num=T.count(r);
    cout<<num<<endl;
    system("pause");
    return 0;
}
