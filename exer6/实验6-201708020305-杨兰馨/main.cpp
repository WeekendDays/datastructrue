#include <iostream>
using namespace std;
//#define  INF 1<<30
#include "MatrixGraph.h"
#include "MatrixGraph.cpp" 

int vt[1001][1001];
int main()
{
	bool flag = 0;//确定该图为有向图 
	int N,M;
	cin>>N>>M;
	MatrixGraph ma(N);
	ma.setType(flag);
	int v1,v2,w;
	for(int i=0;i<M;i++)
	{
		cin>>v1>>v2;
		ma.setEdge(v1-1,v2-1);
	}
	int count=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			ma.DFSTraverse(&ma,j);
			vt[i][j]=ma.getMark(i);
			ma.resetMark();
		}
	}
	for(int i=0;i<N;i++)
	{
		int sum=0;
		for(int j=0;j<N;j++)
		{
			if(vt[i][j]==1||vt[j][i]==1) sum++;
		}
		if(sum==ma.n()) count++;
	}
	cout<<count<<endl;
	system ("pause") ;
	return 0;
}
