#include <iostream>
using namespace std;
//#define  INF 1<<30
#include "MatrixGraph.h"
#include "MatrixGraph.cpp" 

bool judge(int, int, int, int wt = INFINITY);
int main() 
{
	for(int i = 1; i <= 50; i++) cout<<'*';
    cout<<"\nʵ���壺ͼ������ʵ�֣��ڽӾ���\n";
	for(int i=1;i<=50;i++) cout<<'*';
	cout<<endl;
	
	cout<<"/*�������ͼ�Ĵ���*/"<<endl;
	cout<<"ѡ��ͼ�����ͣ�0. ����ͼ 1. ����ͼ��";
	int a; cin>>a;
	bool flag = a;
	cout<<"������ͼ�ж������Ŀ��";
	int n; cin>>n;
	MatrixGraph ma(n);
	ma.setType(a);
	int v1,v2,wt;
	cout<<"������ͼ�еıߵ���Ŀ��";
	int e; cin>>e;
	cout<<"����ÿһ������һ������Ϣ"<<endl;
	cout<<"����Ϣ���������������ֱ������v1������v2���Լ���������֮��ߵ�Ȩֵ"<<endl; 
	cout<<"���磺���� 2 3 1 ��ʾ����2�붥��3֮���һ��ȨֵΪ1�ı�"<<endl;
	for(int i = 0; i < e; i++)
	{
		cin>>v1>>v2>>wt;
		if(!judge(n,v1,v2,wt)){
			continue;
		}
		ma.setEdge(v1,v2,wt);
	}
	cout << "��ͼ�ɹ�!"<<endl;
	cout << "========ѡ��Ҫִ�еĲ���========" <<endl;
    cout << " 1.�����ǰͼ���ڽӾ���"<<endl;
	cout << " 2.�����µı߻���ı�Ȩ" <<endl;
    cout << " 3.ɾ��һ����" <<endl;
    cout << " 4.�ж��Ƿ���ĳ����" <<endl;
    cout << " 5.��ȡ�ߵ���Ŀ" <<endl;
    cout << " 6.�Ե�ǰͼ����������ȱ���DFS" <<endl;
    cout << " 7.�Ե�ǰͼ���й�����ȱ���BFS" <<endl;
    cout << " 8.���ٵ�ǰͼ"<<endl;
    cout << " 0.�˳�" <<endl;
    cout << "=============================" <<endl;
    while(true)
    {
    	cout<<"��������Ҫ��֤�Ĺ��ܣ�";
    	int order;
    	cin>>order;
    	if(order == 0){
    		break;
		}
		switch (order) {
			case 1:{
				cout<<"ͼ���ڽӾ���"<<endl;
				ma.printGraph();
				cout<<endl;
				break;
			}
			case 2:{
				cout<<"������Ҫ���õ��µıߵ���Ϣ�����뷽ʽͬ��ͼʱ��Ҫ��"<<endl;
				cin>>v1>>v2>>wt;
				if(!judge(n,v1,v2,wt)){
					continue;
				} 
				ma.setEdge(v1,v2,wt);
				cout<<"����ɹ�������˿̵��ڽӾ���"<<endl;
				ma.printGraph();
				cout<<endl; 
				break;
			}
			case 3:{
				cout<<"���Ѵ��ڵı��У�ѡ����Ҫɾ���ıߣ������������ߵ���������"<<endl;
				cout<<"���磺���� 0 2 ��ʾɾ������0 2����ı�"<<endl;
				cin>>v1>>v2;
				if(ma.isEdge(v1,v2)==false){
					cout<<"�����������б����Ͳ����ڱߣ�ɾ��ʧ�ܡ�"<<endl;
					cout<<endl;
				}
				else
				{
					ma.deleteEdge(v1,v2);
					cout<<"ɾ���ɹ��������ͼ���ڽӾ���"<<endl;
					ma.printGraph();
					cout<<endl;
				}
				break;
			}
			case 4:{
				cout<<"�������������㣬������ж������������֮���Ƿ���ڱ�"<<endl;
				cout<<"���磺���� 0 2 �ж϶���0�Ͷ���2֮���Ƿ���ڱ�"<<endl;
				cin>>v1>>v2;
				if(ma.isEdge(v1,v2)==false) cout<<"����������֮�䲻���ڱ�"<<endl;
				else cout<<"����������֮����ڱ�"<<endl;
				cout<<endl; 
				break;
			}
			case 5:{
				cout<<"�ߵĸ��� = "<<ma.e()<<endl;
				cout<<endl;
				break;
			}
			case 6:{
				cout<<"����Ҫ����ͼ��DFS"<<endl;
				cout<<"��������Ϊ��ʼ����(���磺0)��";
				cin>>v1;
				if(v1<n && v1>=0){
					cout<<"���Ϊ��";
					ma.DFSTraverse(&ma,v1);
				    cout<<endl;
				    cout<<endl;
				    ma.resetMark();
				} 
				else cout<<"����Ķ��㲻���ڣ����㷶ΧӦΪ0~"<<ma.n()-1<<endl<<endl; 
				break;
			}
			case 7:{
				cout<<"����Ҫ����ͼ��BFS"<<endl;
				cout<<"��������Ϊ��ʼ����(���磺0)��";
				cin>>v1;
				if(v1<n && v1>=0){
				AQueue q(101);
				cout<<"���Ϊ��";
				ma.BFSTraverse(&ma,v1,&q);
				cout<<endl;
				cout<<endl;
				ma.resetMark();}
				else cout<<"����Ķ��㲻���ڣ����㷶ΧӦΪ0~"<<ma.n()-1<<endl<<endl; 
				break;
			}
			case 8:{
				cout<<"ͼ������"<<endl<<endl;
				ma.cclear();
				break;
			}
			default:
				break;
		}
	}
	return 0;
}
bool judge(int n, int vt1, int vt2, int wt) {
    if (vt1 >= n || vt2 >= n) {
        cout << "�Ƿ����룬����ķ�Χ��0-" << n - 1 << endl;
        return false;
    }
    if (vt1 == vt2) {
        cout << "�Ƿ����룬�������㲻�����" << endl;
        return false;
    }
    if (wt <= 0) {
        cout << "�Ƿ����룬��ȨӦ����0" << endl;
        return false;
    }
    return true;
}
