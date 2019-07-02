#include "sxlist.h"
#include<iostream>
using namespace std;

sxlist::sxlist()
{
	init();
}
sxlist::~sxlist()
{
	removeall();
}
Node::Node(double c,int i,Node *ptr)
{
	coef = c;
    index = i;
    next = ptr;
}
Node::Node(Node *ptr)
{
    index = 2147483647;
    coef = 999999;
    next = ptr;
}
void sxlist::clear()
{
	removeall();
	init();
}
void sxlist::insert(double c,int i)
{
	Node *tmp = head;
	if(tmp->next == tail)
        head->next = new Node(c, i, tail);
    else {
        while(tmp->next->index > i) {
            tmp = tmp->next;
        }
        tmp->next = new Node(c, i, tmp->next);
    }
}
double sxlist::getCoef()
{
	return curr->next->coef;
}
int sxlist::getIndex()
{
	return curr->next->index;
}
void sxlist::next()
{
	if(curr->next != tail)
	curr=curr->next; 
}
bool sxlist::hasNext()
{
	if(curr->next != tail) return true;
	else return false;
}
void sxlist::print()
{
	Node* tmp = head;
    Node* s = head;
    if ((int)tmp->next->coef == 1) //第一个结点系数输出规则 
	{
        if (tmp->next->index == 0)
            cout<<'1';
    }
    else if ((int)tmp->next->coef == -1)
	{
        cout<<'-';
    }
    else if((int)tmp->next->coef != 0)
	{
        cout<<tmp->next->coef;
    }
    
    if (tmp->next->index != 0) //第一个结点指数输出规则 
	{
        if (tmp->next->index == 1 && tmp->next->coef !=0) 
		{
            cout<<"x";
        }
        else if(tmp->next->coef != 0)
		{
            cout<<"x^"<<tmp->next->index;
        }
    }
    tmp = tmp->next;
    while (tmp->next != tail) 
	{
        if (tmp->next->coef == 1) 
		{
            if (tmp->next->index == 0)
                cout << "+1";
            else
                cout << '+';
        }
        else if ((int)tmp->next->coef == -1) 
		{
            cout << '-';
        }
        else if ((int)tmp->next->coef != 0) 
		{
            if (tmp->next->coef > 0) 
			{
                cout << '+';
                if (tmp->next->index == 0 && tmp->next->coef == 1)
                    cout << '1';
            }
            cout<<tmp->next->coef;
        }
        
        if (tmp->next->index != 0) {
            if (tmp->next->index == 1 && tmp->next->coef != 0) 
			{
                cout << "x";
            }
            else if(tmp->next->coef != 0) 
			{
                cout << "x^"<< tmp->next->index;
            }
        }
        tmp = tmp -> next;
    }
    cout << endl; 
}
