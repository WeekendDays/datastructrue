#ifndef GRAPH
#define GRAPH
#define VISITED 1
#define UNVISITED 0 //�����˽ڵ������δ���ʵ�����״̬
#define INFINITY 2147483647 //4�ֽ��з������������ֵ

#include <iostream>

class Graph {
public:
    Graph() {}
    ~Graph() {} 

    virtual void Init(int n) = 0;
    virtual int n() = 0;//���ض����ֵ 
    virtual int e() = 0;//���رߵ�ֵ 
    virtual int first(int v) = 0;//���ض���v�ĵ�һ���ھ� 
    virtual int next(int v, int w) = 0;//������w֮����ھ� 
    virtual void setType(bool flag) = 0;//����ͼ������ 
    virtual bool getType() = 0;//��ȡͼ������
	//virtual int locateVex(int u) = 0;//�ҵ�ֵΪu�Ķ����λ��v
	//virtual int getVex(int v) = 0;//����vλ�õĶ����ֵ
	//virtual void putVex(int v,int value) = 0;//��vλ�õĶ��㸳ֵvalue 
	virtual void setEdge(int v1, int v2) = 0;//Ϊ��(v1,v2)����Ȩֵ 
    virtual void deleteEdge(int v1, int v2) = 0;
    virtual bool isEdge(int i, int j) = 0;//�жϱ�(i,j)�Ƿ���ͼ�� 
    //virtual int getWeight(int v1, int v2) = 0;//���رߵ�Ȩֵ 
    virtual int getMark(int v) = 0;//ȡ�ö���ı�־λ 
    virtual void setMark(int v, int val) = 0;//���ö���ı�־λ 
    virtual void printGraph() = 0;//����ͼ 
};


#endif //GRAPH_GRAPH_H
