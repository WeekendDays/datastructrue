#include <iostream>
#include "list.cpp"
#include<iomanip> 
using namespace std;
int main() 
{
	int n;
	Alist<int> L1(100);
	cout<<"----此程序是用来检验顺序表的功能的程序----"<<endl;
	cout<<endl;
	while(1)
	{ 
	cout<<"首先请输入一个整形数字n作为本次检验中顺序表的长度（建议数字不超过100）: ";
	cin>>n;
	cout<<"如您所愿，将构建一个存储"<<n<<"个元素的线性表"<<endl; 
	cout<<"请您依次输入"<<n<<"个数字"<<endl;
	for(int i=0;i<n;i++)
	{
		int e;
		cin>>e;
		L1.append(e);
	}
	cout<<"储存"<<n<<"个元素的顺序表已经构建好，在此期间检验了append函数的添加功能"<<endl;
	cout<<endl;
	cout<<"接下来为您展示这个顺序表中的元素：";
	L1.print();
	cout<<"当前元素的位置为："<<L1.currPos()<<endl;
	cout<<"当前位置的元素为："<<L1.getValue()<<endl; 
	cout<<"此时顺序表的长度为："<<L1.length()<<endl; 
	cout<<endl;
	cout<<"将当前位置设置为pos，请输入pos的值：（注意pos的值要小于此时顺序表的长度）";
	int pos;
	cin>>pos;
	L1.moveToPos(pos);
	cout<<"当前位置的元素为："<<L1.getValue()<<endl;
	cout<<endl;
	cout<<"执行“删除当前位置的元素”的操作" <<endl; 
	cout<<"删除的元素为："<< L1.remove()<<endl;
	cout<<"此时顺序表中的元素为：";
	L1.print();
	cout<<"此时顺序表的长度为："<<L1.length()<<endl; 
	cout<<endl;
	cout<<"将当前位置设置为pos，请输入pos的值：（注意pos的值要小于此时顺序表的长度）";
	int pos1;
	cin>>pos1;
	L1.moveToPos(pos1);
	cout<<"执行“在当前位置插入元素”的操作" <<endl; 
	cout<<"请输入要插入的的元素值：";
	int x;
	cin>>x;
	L1.insert(x);
	cout<<"此时顺序表中的元素为：";
	L1.print();
	cout<<"此时顺序表的长度为："<<L1.length()<<endl; 
	cout<<endl;
	cout<<"下面验证位置移动操作："<<endl;
	cout<<"当前元素的位置为: "<<L1.currPos()<<endl;
	cout<<"当前位置的元素为："<<L1.getValue()<<endl;
	cout<<endl;
	cout<<"验证prev(当前位置左移一步)操作" <<endl;
	L1.prev();
	cout<<"当前元素的位置为: "<<L1.currPos()<<endl;
	cout<<"当前位置的元素为："<<L1.getValue()<<endl;
	cout<<endl;
	cout<<"验证next(当前位置右移一步)操作" <<endl;
	L1.next();
	cout<<"当前元素的位置为: "<<L1.currPos()<<endl;
	cout<<"当前位置的元素为："<<L1.getValue()<<endl;
	cout<<endl;
	cout<<"验证movetostart(当前位置设置为顺序表起始处)操作"<<endl;
	L1.moveToStart();
	cout<<"当前元素的位置为: "<<L1.currPos()<<endl;
	cout<<"当前位置的元素为："<<L1.getValue()<<endl;
	cout<<endl;	
	cout<<"验证movetoend(当前位置设置为顺序表末尾)操作"<<endl;
	L1.moveToEnd(); 
	cout<<"当前元素的位置为: "<<L1.currPos()<<endl;
	cout<<"当前位置的元素为："<<L1.getValue()<<endl;
	cout<<endl;
	L1.clear(); 
	cout<<"---第一次验证功能结束,即将开启下一次验证---"<<endl;
	cout<<endl;	} 
	return 0;
}
