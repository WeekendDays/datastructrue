#ifndef GRAPH_MATRIXGRAPH_H
#define GRAPH_MATRIXGRAPH_H
#define VISITED 1
#define UNVISITED 0 //�����˽ڵ������δ���ʵ�����״̬
//#define MAX_VERTEX_NUM 40
#include "Graph.h"
#include "Queue.h"
#include "AQueue.h"

class MatrixGraph : public Graph {
private:
    int numVertex;//���嶥����� 
    int numEdge;//����߸��� 
    int** matrix;//�����ά���� 
    int* mark;//���嶥������ 
    //char vexs[MAX_VERTEX_NUM];//�洢������Ϣ 
    bool undirected;//true��ʾ����ͼ false��ʾ����ͼ
    void Init(int n) ;//��ʼ��ͼ 

public:
    explicit MatrixGraph(int n);
    ~MatrixGraph();
    void cclear();

    int n();//���ض������ 
    int e();//���رߵĸ��� 

    int first(int v);
    int next(int v, int w);
    
    void setType(bool flag);//����ͼ������ 
    bool getType();//��ȡͼ������
    
    //int locateVex(int u);
	//int getVex(int v);
	//void putVex(int v,int value); 
	
    void setEdge(int v1, int v2, int wght);
    void deleteEdge(int v1, int v2);
    bool isEdge(int i, int j);
    
    int getWeight(int v1, int v2);
    int getMark(int v);
    void setMark(int v, int val);
    
    void printGraph();
    
    void resetMark();
    void DFSTraverse(MatrixGraph*, int);
    void BFSTraverse(MatrixGraph*, int, AQueue*); 
};

#endif //GRAPH_MATRIXGRAPH_H
