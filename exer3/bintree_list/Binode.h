#ifndef BINODE_H
#define BINODE_H
#include<iostream>
using namespace std;

typedef char E;

class BiNode{
    private:
	    E it;             // Thenode's value
		BiNode* lc;       //Pointer to left child
		BiNode* rc;      // Pointer to right child
    public:
	    BiNode() { lc = rc = NULL; }
		BiNode(E e,BiNode* l,BiNode* r) { it = e; lc = l; rc = r; }
		E&element() { return it; }
		virtual void setElement(E& e) { it = e; }
		//��������
		BiNode* left() { return lc; }
		void setLeft(BiNode* b) { lc = (BiNode*)b; }
		//�����Һ���
		BiNode* right() { return rc; }
		void setRight(BiNode* b) { rc = (BiNode*)b; }
		//�ж��Ƿ�ΪҶ�ӽڵ�
		bool isLeaf() {return (lc == NULL) && (rc == NULL); }
};
class BinTree:public BiNode{
    private:
	    char c;
		BiNode* root;// Root of the BinTree BinTree���ĸ����
	public:
	    BiNode* Root() { return root; }
	    void setRoot(BiNode* n) { root = n;}
	    void CreateBiTree(char ch);
	    bool BiTreeEmpty(BiNode* rt);
	    void preorder(BiNode* rt);
	    void Inorder(BiNode* rt);
	    void postorder(BiNode* rt);
	    void LevelOrderTraverse(BiNode* rt);
	    int BiTreeDepth(BiNode* rt);
	    int count(BiNode* rt);
};
#endif

