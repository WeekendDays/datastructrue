#include<iostream>
using namespace std;
typedef struct node{
	int data;
	struct node *next;
}Node;// 定义单链表结构
class llist
{
	private:
		int cnt;//size of list
		Node *curr; 
		Node *head;
		Node *tail;
	public:
		llist();
		~llist();
		void init();//初始化 
		void clear();//清空元素
		void insert(int i,int e);//在i位置的结点后插入新的结点
		void append(int e);//在结点的尾部添加结点。
		void removal();//删除当前位置的结点  
		void moveToStart();//当前指针移动到表头
		void MoveToEnd();//当前指针移动到表尾
		bool prev();//当前指针向前移动
		bool Next();//当前指针向后移动
		int length();//返回链表的长度
		int currPos();//返回当前元素的位置
		void moveToPos(int pos);//移动到pos位置的结点
		int getValue();//返回当前位置的元素的值		
		void print();//输出线性表中存储的元素 
 }; 
 
//#endif
