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
//建树
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
	//设置根节点
	T.setRoot(rt);
    return rt;
}
int main()
{
    char ch;
	int depth;
	int num;
	cout<<"提示："<<endl
    <<"以字符串形式输入要构建的二叉树时，按前序遍历的顺序输入，所有的空节点以“/”代替"<<endl
	<<"注意！"
	<<"每一个叶子结点也要表达其两个空结点，用/代替空结点"
	<<"例：ab/d//ce//f//"<<endl;
    cin>>s;
    strcpy(c,s.c_str());
    r=CreateBiTree(c[0]);
    cout<<"判断树是否是空树：";
    if(T.BiTreeEmpty(r))
    {
    	cout<<"该树不是空树"<<endl;
    	cout<<"层次遍历：";
		T.LevelOrderTraverse(r);
		cout<<endl;
		cout<<"前序遍历：";
		T.preorder(r);
		cout<<endl;
		cout<<"中序遍历：";
		T.Inorder(r);
		cout<<endl;
		cout<<"后序遍历：";
		T.postorder(r);
		cout<<endl;
}
    else cout<<"该树是一棵空树"<<endl;
    cout<<"树的高度：";
    depth=T.BiTreeDepth(r);
    cout<<depth<<endl;
    cout<<"树的深度：";
    if (T.BiTreeEmpty(r))
	cout<<depth-1<<endl;
	else cout<<depth<<endl; 
    cout<<"树的结点个数：";
    num=T.count(r);
    cout<<num<<endl;
    system("pause");
    return 0;
}
