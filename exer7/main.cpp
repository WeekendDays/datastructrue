#include <iostream>
#include <fstream> 
using namespace std;
#include "SOList.cpp"

int main() {
	SOAList<string> solist(1111111);
        ifstream infile1("input.txt",ios::in);//输入
        ifstream infile2("find.txt",ios::in);//要查找的数据 
        ofstream outfile("output.txt",ios::out);//输出 
        if(!infile1||!infile2)
        {
    	        cerr<<"open error!\n";
    	        exit(-1);
	}
	string word;
	while(infile1.peek()!=EOF)//初始化 
	{
		infile1>>word;
		solist.append(word);
	}
	
	int count=0;//第count次查找 
	while(infile2.peek()!=EOF)//查找 
	{
		infile2>>word;
		outfile<<"第"<<++count<<"个要查找的汉字是："<<word<<endl; 
		int index=solist.find(word);
		if(index<solist.length())//查找成功 
		{
			outfile<<"查找成功！共查找了"<<index+1<<"次；\n"; 
			solist.trans(index);//查找成功一次转置一次 
		}
		else //查找失败
		{
			outfile<<"查找失败！共查找了"<<index<<"次；\n";
		} 
		outfile<<endl;
	}
	cout<<"查找结束，查找后得到的转置后的序列如下："<<endl;
	for(solist.moveToStart(); solist.currPos() < solist.length(); solist.next()){
		cout<<solist.getValue()<<" ";
	}
	cout<<endl<<endl;
	cout<<"查找结果在文件output.txt中可查看。\n";
	infile1.close();
	infile2.close();
	outfile.close(); 
	return 0;
}

