#include "sxlist.h"
#include <iostream>
using namespace std;
/* run this program using the console pauser
or add your own getch, system("pause") or input loop */
int main() 
{
	cout<<"---该程序实现了两个多项式的相加---"<<endl;
	cout<<"---设两个多项式分别为A(X)，B(X)---"<<endl;
	cout<<endl;
	cout<<"每行输入两个数字，第一个表示幂次，第二个表示该幂次的系数，以空格分离"<<endl;
    cout<<"以0 0结束一个多项式的输入"<<endl;
	cout<<"====输入A(X)====" <<endl;
	double c;
	int i;
	sxlist A,B,C;
	while(cin>>i>>c)
	{
		if(c==0 && i==0) break;
		A.insert(c,i);
	}
	cout<<"您构造的A(X)多项式为：A(X)=";
	A.print(); 
	cout<<endl;
	cout<<"====输入B(X)===="<<endl;
	while(cin>>i>>c)
	{
		if(c==0 && i==0) break;
		B.insert(c,i);
	}
	cout<<"您构造的B(X)多项式为：B(X)=";
	B.print();
	cout<<endl;
	cout<<"则 A(X)+B(X)=";
	double coef;
	while(A.hasNext()==true || B.hasNext()==true)
	{
		if(A.hasNext()==true && B.hasNext()==true)
		{
			int indexA = A.getIndex();
			int indexB = B.getIndex();
			if(indexA == indexB)
			{
				double coefA = A.getCoef();
				double coefB = B.getCoef();
				coef = coefA + coefB;
				if((int)coef != 0)
				C.insert(coef,indexA);
				A.next();
				B.next();
			}
			else if(indexA > indexB)
			{
				coef = A.getCoef();
				C.insert(coef,indexA);
				A.next();
			}
			else
			{
				coef = B.getCoef();
				C.insert(coef,indexB);
				B.next();
			}
		}
        else if (A.hasNext()) 
		{
            int indexA = A.getIndex();
            coef = A.getCoef();
            C.insert(coef, indexA);
            A.next();
        }
        else 
		{
            int indexB = B.getIndex();
            coef = B.getCoef();
            C.insert(coef, indexB);
            B.next();
        }
    }
    C.print();
    cout<<endl;
    A.clear();
    B.clear();
    C.clear();
    system("pause");
	return 0;
}
