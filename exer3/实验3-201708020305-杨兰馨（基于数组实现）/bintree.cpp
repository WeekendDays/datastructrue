#include "bintree.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include "string.h"
#include<queue>
using namespace std;

void BinTree::createTree(string s)
{
	ANode a;
	for(int i=0;s[i]!='\0';i++)
	{
		a.setLeft(i);
		a.setRight(i);
		a.setElement(s[i]);
		nodeArray.push_back(a);
	}
}
bool BinTree::BiTreeEmpty(int rt)
{
	if(nodeArray[rt].element()=='/')
	return true;
	else 
	return false;
}
void BinTree::preorder(int rt)
{
	 if(nodeArray[rt].element()=='/') return;
	 else
	 {
	    cout<<nodeArray[rt].element()<<" ";
		preorder(nodeArray[rt].left());
		preorder(nodeArray[rt].right());
    }
}
void BinTree::Inorder(int rt)
{
	 if(nodeArray[rt].element()!='/')
	 {
	    Inorder(nodeArray[rt].left());
		cout<<nodeArray[rt].element()<<" ";
		Inorder(nodeArray[rt].right());
    }
}
void BinTree::postorder(int rt)
{
    if(nodeArray[rt].element()!='/')
	{
	    postorder(nodeArray[rt].left());
		postorder(nodeArray[rt].right());
		cout<<nodeArray[rt].element()<<" ";
    }
}
void BinTree::LevelOrderTraverse(int rt)
{
    queue<int> q;
    
	if(nodeArray[rt].element()!='/')
	    q.push(rt);

    int temp;
	while(!q.empty())
	{
	    temp=q.front();
		cout<<nodeArray[temp].element()<<' ';
		q.pop();
		int l=nodeArray[temp].left();
		int r=nodeArray[temp].right();
		//左右孩子不为空时则依次入队列
		if(nodeArray[l].element()!='/')
		    q.push(l);
		if(nodeArray[r].element()!='/')
		    q.push(r);
    }
}
int BinTree::BiTreeDepth(int rt)
{
    int lh=0,rh=0 ;
	if(nodeArray[rt].element()!='/')
	{
	    lh=BiTreeDepth(nodeArray[rt].left());
		rh=BiTreeDepth(nodeArray[rt].right());
		return (lh>rh?lh:rh)+1;
    }
	else return 0 ;
}
int BinTree::count(int rt)
{
	if(nodeArray[rt].element()!='/')
	return count(nodeArray[rt].left())+count(nodeArray[rt].right())+1;
	else return 0;
}
