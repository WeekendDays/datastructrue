#include<iostream>
#include "llist.cpp"
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	llist l1;
	l1.init();
	for(int i=1;i<=n;i++)
	{
		l1.append(i);
	}
	l1.moveToStart();
	int tmp=0;
	while(l1.length()!=1)
	{
		tmp++;
		if(tmp%k==0||tmp%10==k)
		{
			if(l1.currPos()+1==l1.length())
			{
				l1.removal();
				l1.moveToStart();
			}
			else l1.removal(); 
		}
		else
		{
			if(l1.currPos()+1==l1.length())
			{
				l1.moveToStart();
			}
			else l1.Next();
		}
	}
	l1.moveToStart();
	cout<<l1.getValue()<<endl;
	return 0;
}
