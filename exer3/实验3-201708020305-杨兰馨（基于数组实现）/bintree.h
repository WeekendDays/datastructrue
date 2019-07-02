#ifndef ANODE_H
#define ANODE_H

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class ANode{
    private:
	    char it;
		int lc;//左孩子在数组中存储的下标 
		int rc;//右兄弟在数组中存储的下标 
		int p;//父节点在数组中存储的下标 
	public:
	    ANode() 
	    {
	    	lc = 0;
	    	rc = 0;
	    	p = 0;
	    	it = '/';
		}
		ANode(char e)
		{
			lc = 0;
			rc = 0;
			p = 0;
			it = e;
		}
        virtual char element() //返回节点元素
		{ return it; }
		virtual void setElement(char e) //设置节点元素
		{ it = e; }      
		virtual int left() //返回左结点下标
		{ return lc; }
		virtual void setLeft(int i) //设置左孩子
		{ lc = 2*i+1; }
		virtual int right() //返回右节点下标
		{ return rc; }
		virtual void setRight(int i) //设置右孩子
		{ rc = 2*i+2; }
};

class BinTree:public ANode
{
	private:
		int root;
		//树的根结点
	public:
		vector<ANode> nodeArray; //用数组存储节点 
		void init() {root = 0;}
		void createTree(string s);
		bool BiTreeEmpty(int rt);//判断是否为空 
		void preorder(int rt); //前序遍历 
		void Inorder(int rt);//中序遍历
		void postorder(int rt);//后序遍历
		void LevelOrderTraverse(int rt);//层次遍历
		int BiTreeDepth(int rt);//树的深度 
		int count(int rt);//结点个数  
}; 

#endif
