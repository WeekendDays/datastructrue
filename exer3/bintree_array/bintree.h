#ifndef ANODE_H
#define ANODE_H

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class ANode{
    private:
	    char it;
		int lc;//�����������д洢���±� 
		int rc;//���ֵ��������д洢���±� 
		int p;//���ڵ��������д洢���±� 
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
        virtual char element() //���ؽڵ�Ԫ��
		{ return it; }
		virtual void setElement(char e) //���ýڵ�Ԫ��
		{ it = e; }      
		virtual int left() //���������±�
		{ return lc; }
		virtual void setLeft(int i) //��������
		{ lc = 2*i+1; }
		virtual int right() //�����ҽڵ��±�
		{ return rc; }
		virtual void setRight(int i) //�����Һ���
		{ rc = 2*i+2; }
};

class BinTree:public ANode
{
	private:
		int root;
		//���ĸ����
	public:
		vector<ANode> nodeArray; //������洢�ڵ� 
		void init() {root = 0;}
		void createTree(string s);
		bool BiTreeEmpty(int rt);//�ж��Ƿ�Ϊ�� 
		void preorder(int rt); //ǰ����� 
		void Inorder(int rt);//�������
		void postorder(int rt);//�������
		void LevelOrderTraverse(int rt);//��α���
		int BiTreeDepth(int rt);//������� 
		int count(int rt);//������  
}; 

#endif
