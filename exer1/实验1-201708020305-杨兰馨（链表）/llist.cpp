#include "llist.h"
#include<iostream>
using namespace std;
void llist::init()
{
	cnt=0;
	head=curr=tail=NULL;
} 
llist::llist()
{
	curr=head=tail=NULL;
	int cnt=0; 
}
llist::~llist()
{
	while(head != NULL) 
	{
		curr=head;
		head=head->next;
		delete curr;
	}
}
void llist::clear()
{
	Node*p=head;
	while(head)
	{
		p=head;
		head=head->next;
		delete(p);
	}
	cnt=0;
	head=curr=tail=NULL;
}
void llist::insert(int i,int e)
{
	int pos=0;
	Node *p=head;
	Node *a; 
    while(p!=NULL)
	{
	    if(pos==i)
        {
        	a=(Node*)new Node[1];
        	a->data=e;
		  	if(pos==cnt-1)//在尾结点后面插入 
		    {
		    	a->next=NULL;
		    	p->next=a;
				tail=a;	
			}
			else
			{
				a->next=p->next;
				p->next=a;
				break;
			}
		}
		    p=p->next; 
		    pos++;
	    }
	curr=a;
	cnt++; 		
}
void llist::append(int e)
{
	Node *p=head,*s;
	s=(Node*)new Node[1];
	s->data=e;
	s->next=NULL;
	if(p==NULL)
	{
		head=s;
		curr=head;
	}
	else
	{
	 	while(p->next!=NULL)
		{
			p=p->next;
	 	}
		p->next=s;
	}
	tail=s; 
	cnt++;
}
void llist::removal()
{ 
	Node *a=head;
	if(curr==head)
	{
		head=head->next;
		cnt--; 
		delete(curr);
		curr=head;
	}
	else
	{
		while(a->next!=NULL)
	{
		if(a->next==curr)
		{
			Node *p;
			p=a->next;
			a->next=a->next->next;
			curr=a->next;
			delete p;
			cnt--;
			break;
		}
		else a=a->next;
	}
	}
}
void llist::moveToStart()
{
	curr=head;	
}
void llist::MoveToEnd()
{
	curr=tail;	
}
bool llist::prev()
{
	Node *p = head;
    if (p== curr){
		cout<<"当前元素是头节点，不能执行此操作"<<endl;
		return false; 
	}
	else 
	{
		while(p->next!=NULL)
		{
			if(p->next==curr)
			{
				curr=p;
				cout<<"当前指针向前移动,此时指针所指结点存储的元素是"<<curr->data<<endl;
				return true;
			}
			p=p->next;
		}
	}
}
bool llist::Next()
{
	if(curr==tail)
	{
		cout<<"当前元素是尾结点，不能执行此操作"<<endl;
		return false;
	} 
	else if(curr!=tail)
	{
		curr=curr->next;
		cout<<"当前指针向后移动,此时指针所指结点存储的元素是"<<curr->data<<endl;
		return true;
	}
}
int llist::length()
{
	return cnt;
}
int llist::currPos()
{
	Node *a;
	a=(Node*)new Node[1];
	a=head;
	int i=0;
	while(curr!=a)
	{
		a=a->next;
		i++;
	}
	return i;
}
void llist::moveToPos(int pos)
{
	curr=head;
	for(int i=0;i<pos;i++)
	{
		curr=curr->next;
	}
}
int llist::getValue()
{
	return curr->data;
 }
void llist::print()
{
	Node*p=head;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
} 
