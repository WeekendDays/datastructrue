#include <iostream>
#include "llist.cpp"
using namespace std;
int main() 
{
	llist list;
	int n;
	cout<<"----�˳�����������������Ĺ��ܵĳ���----"<<endl;
	cout<<endl;
	while(1)
	{
	cout<<"����������һ����������n��Ϊ���μ���������ĳ��ȣ��������ֲ�Ҫ̫��: ";
	cin>>n;
	cout<<"������Ը��������һ���洢"<<n<<"��Ԫ�ص����Ա�"<<endl; 
	cout<<"������������"<<n<<"������"<<endl;
	list.init();
	for(int i=0;i<n;i++)
	{
		int e;
		cin>>e;
		list.append(e); 
	}
	cout<<"����"<<n<<"��Ԫ�ص������Ѿ������ã��ڴ��ڼ������append��������ӹ���"<<endl;
	cout<<endl;
	cout<<"������Ϊ��չʾ��������е�Ԫ�أ�";
	list.print();
	cout<<"��ǰ���ָ���λ��Ϊ��"<<list.currPos()<<endl;
	cout<<"��ǰλ�õ�Ԫ�ص�ֵΪ��"<<list.getValue()<<endl; 
	cout<<"��ʱ����ĳ���Ϊ��"<<list.length()<<endl; 
	cout<<endl;
	cout<<"������Ҫ��ָ���ƶ�����posλ�ã���ע��pos��ֵҪС�ڴ�ʱ����ĳ��ȣ�";
	int pos;
	cin>>pos;
	list.moveToPos(pos);
	cout<<"��ǰλ�õ�Ԫ�ص�ֵΪ��"<<list.getValue()<<endl; 
	cout<<endl; 
	cout<<"ִ�С�ɾ����ǰλ�õĽ�㡱�Ĳ���"<<endl;
	list.removal();
	cout<<"ɾ�����󣬴�ʱ�����е�Ԫ��Ϊ��";
	list.print();
	cout<<"��ʱ����ĳ���Ϊ��"<<list.length()<<endl;
	cout<<endl;
	cout<<"������֤�������"<<endl; 
	cout<<"��Ҫ��posλ�ú�������㣬��������ϣ����posλ�ã���ע��pos��ֵҪС�ڴ�ʱ����ĳ��ȣ�"; 
	int pos1;
	cin>>pos1;
	cout<<"������Ҫ���뵽��λ�õ�Ԫ��ֵ��" ;
	int x;
	cin>>x;
	list.insert(pos1,x);
	cout<<"������󣬴�ʱ�����е�Ԫ��Ϊ��";
	list.print();
	cout<<"��ʱ����ĳ���Ϊ��"<<list.length()<<endl;
	cout<<endl;
	cout<<"������ָ֤���ƶ�������"<<endl;
	cout<<"��ǰ���ָ���λ��Ϊ: "<<list.currPos()<<endl;
	cout<<"��ʱָ��ָ��Ľ��Ϊ��"<<list.getValue()<<endl;
	cout<<endl;
	cout<<"��֤prev(��ǰָ����ǰ�ƶ�)����" <<endl;
	list.prev();
	cout<<"��ǰ���ָ���λ��Ϊ: "<<list.currPos()<<endl;
	cout<<"��ʱָ��ָ��Ľ��Ϊ��"<<list.getValue()<<endl;
	cout<<endl;
	cout<<"��֤next(��ǰָ������ƶ�)����" <<endl;
	list.Next();
	cout<<"��ǰ���ָ���λ��Ϊ: "<<list.currPos()<<endl;
	cout<<"��ʱָ��ָ��Ľ��Ϊ��"<<list.getValue()<<endl;
	cout<<endl;
	cout<<"��֤movetostart(��ǰָ��ָ���׽��)����"<<endl;
	list.moveToStart();
	cout<<"��ǰ���ָ���λ��Ϊ: "<<list.currPos()<<endl;
	cout<<"��ʱָ��ָ��Ľ��Ϊ��"<<list.getValue()<<endl;
	cout<<endl;	
	cout<<"��֤movetoend(��ǰָ��ָ��β���)����"<<endl;
	list.MoveToEnd(); 
	cout<<"��ǰ���ָ���λ��Ϊ: "<<list.currPos()<<endl;
	cout<<"��ʱָ��ָ��Ľ��Ϊ��"<<list.getValue()<<endl;
	cout<<endl;	
	list.clear();
	cout<<"---��һ����֤���ܽ���,����������һ����֤---"<<endl;
	cout<<endl;
	} 
	return 0;
}
