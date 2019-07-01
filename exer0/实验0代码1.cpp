#include<iostream>
using namespace std;
typedef struct node{
	int element;
	struct node *next;
}Node;//定义单链表结构 
class LList
{
	public:
		int listsize;
//		Node *curr;
		Node *head;
//		Node *tail;
		LList()
		{
			head=NULL;
			listsize=0;
		}
		~LList();
		void append(int e); 
		void func(int e,int n,int q);//执行题目所需所有要求；  
		void print();
		int length();
};
LList::~LList()
{
	Node *p=head;
	while(head)
	{
		p=head;
		head=head->next;
		delete(p);
	}
	listsize=0;
}
int LList::length()
{
	return listsize;
}
void LList::append(int e)
{
	Node *p=head, *s;
	s=(Node*)new Node[1];
	s->element=e;
	s->next=NULL;
	if(p==NULL)
	{
		head=s;
	}
	else
	{
	 	while(p->next!=NULL)
		{
			p=p->next;
	 	}
		p->next=s;
	 }
	 listsize++;
}
void LList::func(int e,int n,int q)
{
	Node *p=head;
	int pos=0;
	Node *a;
//	a=NULL;
	while(p!=NULL)
	{
		if(head->element==e)
		{
			head=head->next;
			delete p;
			break;
		}
		else if(p->next->element==e)
		{
			Node *q1;
			q1=p->next;
			p->next=p->next->next;
			pos=pos+q;
			delete q1;
			break;
		}
		else p=p->next;
		pos++;
	}
	Node *p1=head;
	int pos1=0;
	while(pos1!=n-1)
	{
		if(pos+1==0)
		{
			a= (Node *)new Node[1];
			a->element=e; 
			a->next=p1;
			head=a;
			break;
		}
		else if(pos1==pos)
		{
			a= (Node *)new Node[1];
			a->element=e;
			a->next=p1->next;
			p1->next=a;
			break;
		}
		else p1=p1->next;
		pos1++;
	}
}
void LList::print()
{
	Node *p2;
	for(p2=head;p2!=NULL;p2=p2->next)
	{
		cout<<p2->element<<" ";
	}
	cout<<endl;
} 
int main()
{
	LList llist;
	int n,m;
	int p[1001],q[1001];
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>p[i]>>q[i];
	}
	for(int i=1;i<=n;i++)
	{
		llist.append(i);
	}
	cout<<llist.length()<<endl;
	for(int i=0;i<m;i++)
	{
		llist.func(p[i],n,q[i]);
	}
	llist.print();
	return 0;
} 

