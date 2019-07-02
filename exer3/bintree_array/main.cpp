#include <iostream>
#include<iomanip>
#include "bintree.h"
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int main() 
{
	cout<<"提示："<<endl
    <<"以字符串形式输入要构建的二叉树时，按层次遍历的顺序输入，所有的空节点以“/”代替"<<endl
	<<"注意！"<<endl
	<<"必须要表示到最后一个叶子结点的下一层的两个空指针"
	<<"例：abc//de////f/////////////"<<endl
	<<"请输入："; 
	BinTree t;
	string str;
	cin>>str;
	int rt=0;
	t.init();
	t.createTree(str);
	cout<<"判断树是否是空树：";
	if(t.BiTreeEmpty(rt)==true) 
	cout<<"输入是一颗空树"<<endl;
	else
	{
		cout<<"输入不是空树"<<endl;
		cout<<"层次遍历：";
		t.LevelOrderTraverse(rt);
		cout<<endl<<endl;
	    cout<<"前序遍历："; 
	    t.preorder(rt);
	    cout<<endl<<endl;
	    cout<<"中序遍历：";
        t.Inorder(rt); 
        cout<<endl<<endl;
        cout<<"后序遍历：";
	    t.postorder(rt);
	    cout<<endl<<endl; 
	} 
	cout<<"树的高度：" <<t.BiTreeDepth(rt)<<endl;
	cout<<"树的结点的个数："<<t.count(rt)<<endl; 
	system("pause");
	return 0;
}
