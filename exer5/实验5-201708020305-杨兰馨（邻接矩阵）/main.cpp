#include <iostream>
using namespace std;
//#define  INF 1<<30
#include "MatrixGraph.h"
#include "MatrixGraph.cpp" 

bool judge(int, int, int, int wt = INFINITY);
int main() 
{
	for(int i = 1; i <= 50; i++) cout<<'*';
    cout<<"\n实验五：图的物理实现（邻接矩阵）\n";
	for(int i=1;i<=50;i++) cout<<'*';
	cout<<endl;
	
	cout<<"/*首先完成图的创建*/"<<endl;
	cout<<"选择图的类型：0. 有向图 1. 无向图：";
	int a; cin>>a;
	bool flag = a;
	cout<<"请输入图中顶点的数目：";
	int n; cin>>n;
	MatrixGraph ma(n);
	ma.setType(a);
	int v1,v2,wt;
	cout<<"请输入图中的边的数目：";
	int e; cin>>e;
	cout<<"下面每一行输入一个边信息"<<endl;
	cout<<"边信息包括三个整数，分别代表顶点v1，顶点v2，以及两个顶点之间边的权值"<<endl; 
	cout<<"例如：输入 2 3 1 表示顶点2与顶点3之间的一条权值为1的边"<<endl;
	for(int i = 0; i < e; i++)
	{
		cin>>v1>>v2>>wt;
		if(!judge(n,v1,v2,wt)){
			continue;
		}
		ma.setEdge(v1,v2,wt);
	}
	cout << "建图成功!"<<endl;
	cout << "========选择要执行的操作========" <<endl;
    cout << " 1.输出当前图的邻接矩阵"<<endl;
	cout << " 2.设置新的边或更改边权" <<endl;
    cout << " 3.删除一条边" <<endl;
    cout << " 4.判断是否有某条边" <<endl;
    cout << " 5.获取边的数目" <<endl;
    cout << " 6.对当前图进行深度优先遍历DFS" <<endl;
    cout << " 7.对当前图进行广度优先遍历BFS" <<endl;
    cout << " 8.销毁当前图"<<endl;
    cout << " 0.退出" <<endl;
    cout << "=============================" <<endl;
    while(true)
    {
    	cout<<"请输入您要验证的功能：";
    	int order;
    	cin>>order;
    	if(order == 0){
    		break;
		}
		switch (order) {
			case 1:{
				cout<<"图的邻接矩阵："<<endl;
				ma.printGraph();
				cout<<endl;
				break;
			}
			case 2:{
				cout<<"请输入要设置的新的边的信息，输入方式同建图时的要求："<<endl;
				cin>>v1>>v2>>wt;
				if(!judge(n,v1,v2,wt)){
					continue;
				} 
				ma.setEdge(v1,v2,wt);
				cout<<"插入成功，输出此刻的邻接矩阵："<<endl;
				ma.printGraph();
				cout<<endl; 
				break;
			}
			case 3:{
				cout<<"在已存在的边中，选择您要删除的边，并输入这条边的两个顶点"<<endl;
				cout<<"例如：输入 0 2 表示删除连接0 2顶点的边"<<endl;
				cin>>v1>>v2;
				if(ma.isEdge(v1,v2)==false){
					cout<<"这两个顶点中本来就不存在边，删除失败。"<<endl;
					cout<<endl;
				}
				else
				{
					ma.deleteEdge(v1,v2);
					cout<<"删除成功，输出该图的邻接矩阵："<<endl;
					ma.printGraph();
					cout<<endl;
				}
				break;
			}
			case 4:{
				cout<<"请输入两个顶点，下面会判断这个两个顶点之间是否存在边"<<endl;
				cout<<"例如：输入 0 2 判断顶点0和顶点2之间是否存在边"<<endl;
				cin>>v1>>v2;
				if(ma.isEdge(v1,v2)==false) cout<<"这两个顶点之间不存在边"<<endl;
				else cout<<"这两个顶点之间存在边"<<endl;
				cout<<endl; 
				break;
			}
			case 5:{
				cout<<"边的个数 = "<<ma.e()<<endl;
				cout<<endl;
				break;
			}
			case 6:{
				cout<<"下面要进行图的DFS"<<endl;
				cout<<"请输入作为起始顶点(例如：0)：";
				cin>>v1;
				if(v1<n && v1>=0){
					cout<<"结果为：";
					ma.DFSTraverse(&ma,v1);
				    cout<<endl;
				    cout<<endl;
				    ma.resetMark();
				} 
				else cout<<"输入的顶点不存在，顶点范围应为0~"<<ma.n()-1<<endl<<endl; 
				break;
			}
			case 7:{
				cout<<"下面要进行图的BFS"<<endl;
				cout<<"请输入作为起始顶点(例如：0)：";
				cin>>v1;
				if(v1<n && v1>=0){
				AQueue q(101);
				cout<<"结果为：";
				ma.BFSTraverse(&ma,v1,&q);
				cout<<endl;
				cout<<endl;
				ma.resetMark();}
				else cout<<"输入的顶点不存在，顶点范围应为0~"<<ma.n()-1<<endl<<endl; 
				break;
			}
			case 8:{
				cout<<"图已销毁"<<endl<<endl;
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
        cout << "非法输入，顶点的范围是0-" << n - 1 << endl;
        return false;
    }
    if (vt1 == vt2) {
        cout << "非法输入，两个顶点不能相等" << endl;
        return false;
    }
    if (wt <= 0) {
        cout << "非法输入，边权应大于0" << endl;
        return false;
    }
    return true;
}
