#include "llist.h"
#include<iostream>
using namespace std;

template<typename E>
void LList<E>::init(){
	curr=tail=head=new Link<E>;
	head->next=NULL;
	cnt=0;
}
	
template<typename E>
void LList<E>::removeall(){
	while(head!=NULL){
		curr=head;
		head=head->next;
		delete curr;
	}	
}
	
template<typename E>
LList<E>::LList(int size){
	init();
}
	
template<typename E>
LList<E>::~LList(){
	removeall();
}
	
template<typename E>
void LList<E>::print() const{
	Link<E>* temp=head->next;
	while(temp!=NULL){
		cout<<temp->element<<' ';
		temp=temp->next;
	}
}
	
template<typename E>
void LList<E>::clear(){
	removeall();
	init();
}
	
template<typename E>
void LList<E>::insert(const E& it){
	curr->next=new Link<E>(it,curr->next);
	if(tail==curr) tail=curr->next;
	cnt++;
}
	
template<typename E>
void LList<E>::append(const E& it){
	tail=tail->next=new Link<E>(it,NULL);
	cnt++;
}
	
template<typename E>
E LList<E>::remove(){
//	if(curr->next==NULL){
//		cout<<"No element"<<endl;
//		return 0;
//	}
	E it=curr->next->element;
	Link<E>* temp=curr->next;
	if(tail==curr->next) tail=curr;
	curr->next=curr->next->next;
	delete temp;
	cnt--;
	return it;
}
	
template<typename E>
void LList<E>::moveToStart(){
	curr=head;
}
	
template<typename E>
void LList<E>::moveToEnd(){
	curr=tail;
}
	
template<typename E>
void LList<E>::prev(){
	if(curr==head){
		cout<<"curr is the head\n";
		return;
	} 
	Link<E>* temp=head;
	while(temp->next!=curr) temp=temp->next;
	curr=temp;
}
	
template<typename E>
void LList<E>::next(){
	if(curr==tail){
		cout<<"curr is the tail\n";
		return;
	}
	curr=curr->next;
}
	
template<typename E>
int LList<E>::length() const{
	return cnt;
}
	
template<typename E>
int LList<E>::currPos() const{
	Link<E>* temp=head;
	int i;
	for(i=0;temp!=curr;i++)
	temp=temp->next;
	return i;
}

template<typename E>
void LList<E>::moveToPos(int pos){
	if(pos<0||pos>cnt){
		cout<<"Position out of tange\n";
	}
	curr=head;
	for(int i=0;i<pos;i++) curr=curr->next;
}
	
template<typename E>
const E& LList<E>::getValue() const{
//	if(curr->next==NULL){
//		cout<<"No value\n";
//		return -1;
//    }
	return curr->next->element;
}

