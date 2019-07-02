#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
template<typename E>
void swap(E a[],const int &i,const int &j){
	E t=a[i];
	a[i]=a[j];
	a[j]=t;
}
//�������� 
template<typename E>
void inssort(E a[],int n){
	for(int i=1;i<n;i++){
		for(int j=i;(j>0)&&(a[j]<a[j-1]);j--){
			swap(a,j,j-1);
		}
	}
}
//ϣ������ 
template<typename E> 
void inssort2(E a[],int n,int incr){//incrΪ�������� 
	for(int i=incr;i<n;i+=incr){//����Ϊ������ 
		for(int j=i;(j>=incr)&&(a[j]<a[j-incr]);j-=incr){
			swap(a,j,j-incr);
		}
	}
}
template<typename E>
void shellsort(E a[],int n){
	for(int i=n/2;i>2;i/=2){
		for(int j=0;j<i;j++){
			inssort2(&a[j],n-j,i);
			//inssort2(&a,n-j,i);
		}
	}
	inssort2(a,n,1);
}
int a[1000001],b[1000001],c[1000001],d[1000001],temp[1000001];
void show(ifstream &q,ofstream&p)
{
	int n=0;
	clock_t t,t1;
	int tt;
	while(q>>tt){
		 a[n]=tt;
		 b[n]=a[n];
		 c[n]=a[n];
		 d[n]=a[n];
		 n++;
	}
	cout<<"���¶�"<<n<<"�����ݽ��бȽ�����ͬ�������ĵ�ʱ�䣨��ȷ�����룩��"<<endl; 
	p<<"�����ǽ��в�ͬ�����Ľ����"<<endl; 
	q.close(); 
	
	t=clock();
	inssort(b,n);
	t1=clock();
	p<<"��������Ľ�����£�"<<endl;
	for(int i=0;i<n;i++)
	{	
		p<<b[i]<<" ";
		if((i+1)%10==0)p<<endl;
	 } 
	cout<<"��������"<<(double)(t1-t)*1000/CLOCKS_PER_SEC<<"ms"<<endl;
	p<<endl;
	
	t=clock();
	shellsort(c,n);
	t1=clock();
	p<<"ϣ������Ľ�����£�"<<endl;
	for(int i=0;i<n;i++)
	{	
		p<<c[i]<<" ";
		if((i+1)%10==0)p<<endl;
	 }
	 p<<endl;
	cout<<"ϣ������"<<(double)(t1-t)*1000/CLOCKS_PER_SEC<<"ms"<<endl;
	
	p.close();
	
 } 
int main(){
	ifstream in100("in100.txt");
	ofstream out100("out100.txt");
	show(in100,out100);
	cout<<endl;
	ifstream in1k("in1k.txt");
	ofstream out1k("out1k.txt");
	show(in1k,out1k);
	cout<<endl;
	ifstream in10k("in10k.txt");
	ofstream out10k("out10k.txt");
	show(in10k,out10k);
	cout<<endl;
	ifstream in100k("in100k.txt");
	ofstream out100k("out100k.txt");
	show(in100k,out100k);
	cout<<endl;
	ifstream in1M("in1M.txt");
	ofstream out1M("out1M.txt");
	show(in1M,out1M);
	cout<<endl;
	system("pause"); 
	return 0;
} 
 
