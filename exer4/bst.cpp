#include "bst.h"
#include <cmath>
#include<iostream>
using namespace std;
int findsum=0;
void bst::clearHelp(Node* node)
{
	if(node == NULL) return ;
	clearHelp(node->left());
	clearHelp(node->right());
	delete node;
}

Node* bst::insertHelp(Node* subroot,const int& k)
{
	if(subroot==NULL) return new Node(k,NULL,NULL);//
	if(k < subroot->getKey())
	{
		subroot->setLeft(insertHelp(subroot->left(),k));
	}
	else
	{
		subroot->setRight(insertHelp(subroot->right(),k));
	}
	return subroot;
}

int bst::findHelp(Node* subroot, const int& k) const
{
	findsum++;
	if(subroot==NULL) return -1;
	else if(k < subroot->getKey())
	{
		return findHelp(subroot->left(),k);
	}
	else if(k > subroot->getKey())
	{
		return findHelp(subroot->right(),k);
	}
	else return findsum;
}

bst::bst()
{
	root = NULL;
	count = 0;
}

bst::~bst()
{
	clearHelp(root);
}

void bst::clear()
{
	clearHelp(root);
	root = NULL;
	count = 0;
}

void bst::insert(const int& k)
{
	root = insertHelp(root,k);
	count++;
}

void bst::find(const int& k) const
{
	findsum=0;
	int sum = findHelp(root,k);
	if(sum<0)
	{
		cout<<"查找失败,该树中没有这个元素"<<endl;
	}
	else
	{
		cout<<"查找成功，查找次数为："<<sum<<endl;
	}
}
