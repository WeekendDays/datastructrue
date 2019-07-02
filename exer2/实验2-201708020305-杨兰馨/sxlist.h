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
			tail = new Node(-1,-1);//��Ϊ����ʽ����С����Ϊ0 
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
		sxlist();//���캯�� 
		~sxlist();//��������
		void insert(double c,int i);//˳�������ʵ��
		void next();//ָ��ָ����һ��� 
		int getIndex();//��ȡ��ָ�� 
		double getCoef();//��ȡϵ�� 
		bool hasNext();//�ж���������һ�� 
		void print();//������� 
		void clear();//��ͷ���� 
};

#endif
