#include<iostream>
using namespace std;
typedef struct node{
	int data;
	struct node *next;
}Node;// ���嵥����ṹ
class llist
{
	private:
		int cnt;//size of list
		Node *curr; 
		Node *head;
		Node *tail;
	public:
		llist();
		~llist();
		void init();//��ʼ�� 
		void clear();//���Ԫ��
		void insert(int i,int e);//��iλ�õĽ�������µĽ��
		void append(int e);//�ڽ���β����ӽ�㡣
		void removal();//ɾ����ǰλ�õĽ��  
		void moveToStart();//��ǰָ���ƶ�����ͷ
		void MoveToEnd();//��ǰָ���ƶ�����β
		bool prev();//��ǰָ����ǰ�ƶ�
		bool Next();//��ǰָ������ƶ�
		int length();//��������ĳ���
		int currPos();//���ص�ǰԪ�ص�λ��
		void moveToPos(int pos);//�ƶ���posλ�õĽ��
		int getValue();//���ص�ǰλ�õ�Ԫ�ص�ֵ		
		void print();//������Ա��д洢��Ԫ�� 
 }; 
 
//#endif
