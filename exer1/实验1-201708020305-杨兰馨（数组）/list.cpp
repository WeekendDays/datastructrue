#include"list.h"
#include<assert.h>
#include<iostream>
using namespace std;
template<typename E>
class Alist: public List<E>{
	private:
		int maxsize;//˳�������� 
		int listsize;//Ŀǰ�Ĵ�С 
		int curr;//��ǰԪ�ص�λ�� 
		E *listArray;//�б�Ԫ�ؽ���ŵ��������� 
	public:
		Alist(int size=100)
		{
			maxsize=size;
			listsize=curr=0;
			listArray=new E[maxsize]; 
		}
		~Alist()
		{
			delete [] listArray;
		}
		void clear()
		{
			delete [] listArray;
			listsize=curr=0;
			listArray=new E[maxsize];
		}
		void insert(const E& it)
		{
			assert(listsize<maxsize);
			for(int i=listsize;i>curr;i--)
			listArray[i]=listArray[i-1];
			listArray[curr]=it;
			listsize++;
		}
		void append(const E& it)
		{
			assert(listsize<maxsize);
			listArray[listsize++]=it;
		}
		E remove()
		{
			assert((curr>=0)&&(curr<listsize));
			E it=listArray[curr];
			for(int i=curr;i<listsize-1;i++)
			{ listArray[i]=listArray[i+1];}
			listsize--;
			return it;
		}
		void moveToStart() {curr=0;}
		void moveToEnd() {curr=listsize-1;}
		bool prev()
		{
			if(curr==0)
			{
				cout<<"��ǰλ��Ϊ��λ�ã�����ִ�д˲���"<<endl;
				return false;
			}
			else if(curr!=0)
			{
				curr--;
				return true;
			}
		}
		bool next()
		{
			if(curr==listsize-1)
			{
				cout<<"��ǰλ��Ϊβλ�ã�����ִ�д˲���"<<endl;
				return false; 
			}
			else if(curr<listsize-1)
			{
				curr++;
				return true;
			}
		} 
		int length() const {return listsize;}
		int currPos() const {return curr;}
		void moveToPos(int pos)
		{
			assert((pos>=0)&&(pos<=listsize));
			curr=pos;
		}
		const E& getValue() const
		{
		assert((curr>=0)&&(curr<listsize));
		return listArray[curr];
		}
		void print()
		{
			for(int i=0;i<listsize;i++)
			{
				cout<<listArray[i]<<" ";
			}
			cout<<endl;
		}
}; 
