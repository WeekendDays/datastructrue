#include <iostream>
#include <fstream> 
using namespace std;
#include "SOList.cpp"

int main() {
	SOAList<string> solist(1111111);
        ifstream infile1("input.txt",ios::in);//����
        ifstream infile2("find.txt",ios::in);//Ҫ���ҵ����� 
        ofstream outfile("output.txt",ios::out);//��� 
        if(!infile1||!infile2)
        {
    	        cerr<<"open error!\n";
    	        exit(-1);
	}
	string word;
	while(infile1.peek()!=EOF)//��ʼ�� 
	{
		infile1>>word;
		solist.append(word);
	}
	
	int count=0;//��count�β��� 
	while(infile2.peek()!=EOF)//���� 
	{
		infile2>>word;
		outfile<<"��"<<++count<<"��Ҫ���ҵĺ����ǣ�"<<word<<endl; 
		int index=solist.find(word);
		if(index<solist.length())//���ҳɹ� 
		{
			outfile<<"���ҳɹ�����������"<<index+1<<"�Σ�\n"; 
			solist.trans(index);//���ҳɹ�һ��ת��һ�� 
		}
		else //����ʧ��
		{
			outfile<<"����ʧ�ܣ���������"<<index<<"�Σ�\n";
		} 
		outfile<<endl;
	}
	cout<<"���ҽ��������Һ�õ���ת�ú���������£�"<<endl;
	for(solist.moveToStart(); solist.currPos() < solist.length(); solist.next()){
		cout<<solist.getValue()<<" ";
	}
	cout<<endl<<endl;
	cout<<"���ҽ�����ļ�output.txt�пɲ鿴��\n";
	infile1.close();
	infile2.close();
	outfile.close(); 
	return 0;
}

