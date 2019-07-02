#ifndef SXLIST_H
#define SXLIST_H
#include<iostream>
using namespace std;
struct Node
{
	int index;
	double coef;
	Node *next;
	
	explicit Node(double c,int i,Node *ptr = NULL);
	explicit Node(Node *ptr = NULL);
}; 
class sxlist
{
	private:
		Node *head;
		Node *curr;
		Node *tail;
		void init()
		{
			head = curr = tail = new Node;
			tail = new Node(-1,-1);//因为多项式的最小幂数为0 
			head->next = tail;
		}
		void removeall()
		{
			while(head != NULL)
			{
				curr = head;
				head = head->next;
				delete curr;
			}
		}
	public:
		sxlist();//构造函数 
		~sxlist();//析构函数
		void insert(double c,int i);//顺序链表的实现
		void next();//指针指向下一结点 
		int getIndex();//获取幂指数 
		double getCoef();//获取系数 
		bool hasNext();//判断有无有下一项 
		void print();//遍历输出 
		void clear();//重头再来 
};

#endif
