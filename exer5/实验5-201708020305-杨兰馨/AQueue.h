#include "Queue.h"
#ifndef QUEUE_AQUEUE_H
#define QUEUE_AQUEUE_H
#include<iostream>
using namespace std;
class AQueue: public Queue {
    private:
	    int maxSize;// Maximum size of queue 队列最大容量
		int front; // Index of front element 头部的索引
		int rear; //Index of rear element 尾部索引
		int* listArray; // Array holding queue elements 数组存储队列元素
	public:
	    AQueue(int size = 100) { // Constructor 构造函数
		    maxSize =size+1;
			rear =0;  front = 1;
			listArray =new int[maxSize];
        }
        ~AQueue(){
		    delete [] listArray; 
		} 
        void clear(){
		    rear = 0; front = 1; 
		} 
        void enqueue(int it){ 
		    if((rear+2)%maxSize==front){
			    cout<<"Queue is full"<<endl;
				return;
		    }
            rear =(rear+1) % maxSize; 
			listArray[rear]= it;
        }
        int dequeue(){
		    if(length()==0){
			cout<<"Queue is empty"<<endl;
			return -1;//以-1作为出错的返回值，不严谨 
		   }   
			int it =listArray[front];
			front =(front+1) % maxSize;
			return it;
        }
        int frontValue() { 
		    if(length()==0){
			cout<<"Queue is empty"<<endl;
			return -1;//以-1作为出错的返回值，不严谨 
			}
			return listArray[front];
		}
		int length() { 
		return ((rear+maxSize) - front + 1) %maxSize;
		}
};
#endif

 
