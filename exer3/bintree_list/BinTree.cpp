#include<iostream>
#include "Binode.h"
#include <queue>
using namespace std;

//判断二叉树是否为空
bool BinTree::BiTreeEmpty(BiNode* rt)
{
    if(rt!=NULL) return true;
	else return false;
}
//前序遍历
void BinTree::preorder(BiNode* rt)
{
    if(rt!=NULL)
	{
	    cout<<rt->element()<<" ";
		preorder(rt->left());
		preorder(rt->right());
    }
}
//中序遍历
void BinTree::Inorder(BiNode* rt)
{
    if(rt!=NULL)
	{
	    Inorder(rt->left());
		cout<<rt->element()<<" ";
		Inorder(rt->right());
    }
}
//后序遍历
void BinTree::postorder(BiNode* rt)
{
    if(rt!=NULL)
	{
	    postorder(rt->left());
		postorder(rt->right());
		cout<<rt->element()<<" ";
    }
}
//层次遍历
void BinTree::LevelOrderTraverse(BiNode* rt)
{
    queue<BiNode*> q;
	if(rt!=NULL)
	q.push(rt);
	BiNode* b;
	while(!q.empty())
	{
	    b=q.front();
		cout<<b->element()<<' ';
		q.pop();
		if(b->left())
		    q.push(b->left());
		if(b->right())
		    q.push(b->right());
    }
}
//二叉树深度
int BinTree::BiTreeDepth(BiNode* rt)
{
    int lh=0,rh=0 ;
	if(rt!=NULL)
	{
	    lh=BiTreeDepth(rt->left());
		rh=BiTreeDepth(rt->right());
		return (lh>rh?lh:rh)+1;
    }
	else return 0 ;
}
//节点数统计
int BinTree::count(BiNode* rt)
{
    if(rt)  return count(rt->left())+count(rt->right())+1;
	else return 0;
}
