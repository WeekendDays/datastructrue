#include "sxlist.h"
#include <iostream>
using namespace std;
/* run this program using the console pauser
or add your own getch, system("pause") or input loop */
int main() 
{
	cout<<"---�ó���ʵ������������ʽ�����---"<<endl;
	cout<<"---����������ʽ�ֱ�ΪA(X)��B(X)---"<<endl;
	cout<<endl;
	cout<<"ÿ�������������֣���һ����ʾ�ݴΣ��ڶ�����ʾ���ݴε�ϵ�����Կո����"<<endl;
    cout<<"��0 0����һ������ʽ������"<<endl;
	cout<<"====����A(X)====" <<endl;
	double c;
	int i;
	sxlist A,B,C;
	while(cin>>i>>c)
	{
		if(c==0 && i==0) break;
		A.insert(c,i);
	}
	cout<<"�������A(X)����ʽΪ��A(X)=";
	A.print(); 
	cout<<endl;
	cout<<"====����B(X)===="<<endl;
	while(cin>>i>>c)
	{
		if(c==0 && i==0) break;
		B.insert(c,i);
	}
	cout<<"�������B(X)����ʽΪ��B(X)=";
	B.print();
	cout<<endl;
	cout<<"�� A(X)+B(X)=";
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
