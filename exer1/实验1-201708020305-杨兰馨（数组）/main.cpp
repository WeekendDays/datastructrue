#include <iostream>
#include "list.cpp"
#include<iomanip> 
using namespace std;
int main() 
{
	int n;
	Alist<int> L1(100);
	cout<<"----�˳�������������˳���Ĺ��ܵĳ���----"<<endl;
	cout<<endl;
	while(1)
	{ 
	cout<<"����������һ����������n��Ϊ���μ�����˳���ĳ��ȣ��������ֲ�����100��: ";
	cin>>n;
	cout<<"������Ը��������һ���洢"<<n<<"��Ԫ�ص����Ա�"<<endl; 
	cout<<"������������"<<n<<"������"<<endl;
	for(int i=0;i<n;i++)
	{
		int e;
		cin>>e;
		L1.append(e);
	}
	cout<<"����"<<n<<"��Ԫ�ص�˳����Ѿ������ã��ڴ��ڼ������append��������ӹ���"<<endl;
	cout<<endl;
	cout<<"������Ϊ��չʾ���˳����е�Ԫ�أ�";
	L1.print();
	cout<<"��ǰԪ�ص�λ��Ϊ��"<<L1.currPos()<<endl;
	cout<<"��ǰλ�õ�Ԫ��Ϊ��"<<L1.getValue()<<endl; 
	cout<<"��ʱ˳���ĳ���Ϊ��"<<L1.length()<<endl; 
	cout<<endl;
	cout<<"����ǰλ������Ϊpos��������pos��ֵ����ע��pos��ֵҪС�ڴ�ʱ˳���ĳ��ȣ�";
	int pos;
	cin>>pos;
	L1.moveToPos(pos);
	cout<<"��ǰλ�õ�Ԫ��Ϊ��"<<L1.getValue()<<endl;
	cout<<endl;
	cout<<"ִ�С�ɾ����ǰλ�õ�Ԫ�ء��Ĳ���" <<endl; 
	cout<<"ɾ����Ԫ��Ϊ��"<< L1.remove()<<endl;
	cout<<"��ʱ˳����е�Ԫ��Ϊ��";
	L1.print();
	cout<<"��ʱ˳���ĳ���Ϊ��"<<L1.length()<<endl; 
	cout<<endl;
	cout<<"����ǰλ������Ϊpos��������pos��ֵ����ע��pos��ֵҪС�ڴ�ʱ˳���ĳ��ȣ�";
	int pos1;
	cin>>pos1;
	L1.moveToPos(pos1);
	cout<<"ִ�С��ڵ�ǰλ�ò���Ԫ�ء��Ĳ���" <<endl; 
	cout<<"������Ҫ����ĵ�Ԫ��ֵ��";
	int x;
	cin>>x;
	L1.insert(x);
	cout<<"��ʱ˳����е�Ԫ��Ϊ��";
	L1.print();
	cout<<"��ʱ˳���ĳ���Ϊ��"<<L1.length()<<endl; 
	cout<<endl;
	cout<<"������֤λ���ƶ�������"<<endl;
	cout<<"��ǰԪ�ص�λ��Ϊ: "<<L1.currPos()<<endl;
	cout<<"��ǰλ�õ�Ԫ��Ϊ��"<<L1.getValue()<<endl;
	cout<<endl;
	cout<<"��֤prev(��ǰλ������һ��)����" <<endl;
	L1.prev();
	cout<<"��ǰԪ�ص�λ��Ϊ: "<<L1.currPos()<<endl;
	cout<<"��ǰλ�õ�Ԫ��Ϊ��"<<L1.getValue()<<endl;
	cout<<endl;
	cout<<"��֤next(��ǰλ������һ��)����" <<endl;
	L1.next();
	cout<<"��ǰԪ�ص�λ��Ϊ: "<<L1.currPos()<<endl;
	cout<<"��ǰλ�õ�Ԫ��Ϊ��"<<L1.getValue()<<endl;
	cout<<endl;
	cout<<"��֤movetostart(��ǰλ������Ϊ˳�����ʼ��)����"<<endl;
	L1.moveToStart();
	cout<<"��ǰԪ�ص�λ��Ϊ: "<<L1.currPos()<<endl;
	cout<<"��ǰλ�õ�Ԫ��Ϊ��"<<L1.getValue()<<endl;
	cout<<endl;	
	cout<<"��֤movetoend(��ǰλ������Ϊ˳���ĩβ)����"<<endl;
	L1.moveToEnd(); 
	cout<<"��ǰԪ�ص�λ��Ϊ: "<<L1.currPos()<<endl;
	cout<<"��ǰλ�õ�Ԫ��Ϊ��"<<L1.getValue()<<endl;
	cout<<endl;
	L1.clear(); 
	cout<<"---��һ����֤���ܽ���,����������һ����֤---"<<endl;
	cout<<endl;	} 
	return 0;
}
