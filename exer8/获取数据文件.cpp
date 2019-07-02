#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
	ofstream outfile("in100.txt");
	ofstream outfile1("in1k.txt");
	ofstream outfile2("in10k.txt");
	ofstream outfile3("in100k.txt");
	ofstream outfile4("in1M.txt");
	int a;
	for(int i=0;i<100;i++)
	{
		a=rand()%1000+1;
		outfile<<a<<" ";
		if((i+1)%10==0)outfile<<endl;
	  }  
	for(int i=0;i<1000;i++)
	{
		a=rand();
		outfile1<<a%10000+1<<" ";
		if((i+1)%10==0)outfile1<<endl;
	}
	for(int i=0;i<10000;i++)
	{
		a=rand();
		outfile2<<a%100000+1<<" ";
		if((i+1)%10==0)outfile2<<endl;
	}
	for(int i=0;i<100000;i++)
	{
		a=rand();
		outfile3<<a%1000000+1<<" ";
		if((i+1)%10==0)outfile3<<endl;
	}
	for(int i=0;i<1000000;i++)
	{
		a=rand();
		outfile4<<a%10000000+1<<" ";
		if((i+1)%10==0)outfile4<<endl;
	}
	cout<<"已分别初始化数据规模为100，1K，10K，100K和1M的文件作为排序的输入文件"
		<<endl<<"其文件名分别为in100，in1k，in10k，in100k，in1M"; 
	outfile.close();
	outfile1.close(); 
	outfile2.close();
	outfile3.close();
	outfile4.close();
	return 0;
 } 
