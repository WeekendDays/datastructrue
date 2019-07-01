#include <iostream>
#include "llist.cpp"
using namespace std;
int main() 
{
	llist list;
	int n;
	cout<<"----此程序是用来检验链表的功能的程序----"<<endl;
	cout<<endl;
	while(1)
	{
	cout<<"首先请输入一个整形数字n作为本次检验中链表的长度（建议数字不要太大）: ";
	cin>>n;
	cout<<"如您所愿，将构建一个存储"<<n<<"个元素的线性表"<<endl; 
	cout<<"请您依次输入"<<n<<"个数字"<<endl;
	list.init();
	for(int i=0;i<n;i++)
	{
		int e;
		cin>>e;
		list.append(e); 
	}
	cout<<"储存"<<n<<"个元素的链表已经构建好，在此期间检验了append函数的添加功能"<<endl;
	cout<<endl;
	cout<<"接下来为您展示这个链表中的元素：";
	list.print();
	cout<<"当前结点指针的位置为："<<list.currPos()<<endl;
	cout<<"当前位置的元素的值为："<<list.getValue()<<endl; 
	cout<<"此时链表的长度为："<<list.length()<<endl; 
	cout<<endl;
	cout<<"请输入要将指针移动到的pos位置：（注意pos的值要小于此时链表的长度）";
	int pos;
	cin>>pos;
	list.moveToPos(pos);
	cout<<"当前位置的元素的值为："<<list.getValue()<<endl; 
	cout<<endl; 
	cout<<"执行“删除当前位置的结点”的操作"<<endl;
	list.removal();
	cout<<"删除结点后，此时链表中的元素为：";
	list.print();
	cout<<"此时链表的长度为："<<list.length()<<endl;
	cout<<endl;
	cout<<"下面验证插入操作"<<endl; 
	cout<<"将要在pos位置后面插入结点，请输入您希望的pos位置：（注意pos的值要小于此时链表的长度）"; 
	int pos1;
	cin>>pos1;
	cout<<"请输入要插入到该位置的元素值：" ;
	int x;
	cin>>x;
	list.insert(pos1,x);
	cout<<"插入结点后，此时链表中的元素为：";
	list.print();
	cout<<"此时链表的长度为："<<list.length()<<endl;
	cout<<endl;
	cout<<"下面验证指针移动操作："<<endl;
	cout<<"当前结点指针的位置为: "<<list.currPos()<<endl;
	cout<<"此时指针指向的结点为："<<list.getValue()<<endl;
	cout<<endl;
	cout<<"验证prev(当前指针向前移动)操作" <<endl;
	list.prev();
	cout<<"当前结点指针的位置为: "<<list.currPos()<<endl;
	cout<<"此时指针指向的结点为："<<list.getValue()<<endl;
	cout<<endl;
	cout<<"验证next(当前指针向后移动)操作" <<endl;
	list.Next();
	cout<<"当前结点指针的位置为: "<<list.currPos()<<endl;
	cout<<"此时指针指向的结点为："<<list.getValue()<<endl;
	cout<<endl;
	cout<<"验证movetostart(当前指针指向首结点)操作"<<endl;
	list.moveToStart();
	cout<<"当前结点指针的位置为: "<<list.currPos()<<endl;
	cout<<"此时指针指向的结点为："<<list.getValue()<<endl;
	cout<<endl;	
	cout<<"验证movetoend(当前指针指向尾结点)操作"<<endl;
	list.MoveToEnd(); 
	cout<<"当前结点指针的位置为: "<<list.currPos()<<endl;
	cout<<"此时指针指向的结点为："<<list.getValue()<<endl;
	cout<<endl;	
	list.clear();
	cout<<"---第一次验证功能结束,即将开启下一次验证---"<<endl;
	cout<<endl;
	} 
	return 0;
}
