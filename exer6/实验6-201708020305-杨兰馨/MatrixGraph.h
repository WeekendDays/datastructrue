#ifndef GRAPH_MATRIXGRAPH_H
#define GRAPH_MATRIXGRAPH_H
#define VISITED 1
#define UNVISITED 0 //�����˽ڵ������δ���ʵ�����״̬
#include "Graph.h"

class MatrixGraph : public Graph {
private:
    int numVertex;//���嶥����� 
    int numEdge;//����߸��� 
    int** matrix;//�����ά���� 
    int* mark;//���嶥������ 
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
	
    void setEdge(int v1, int v2);
    void deleteEdge(int v1, int v2);
    bool isEdge(int i, int j);
    
    //int getWeight(int v1, int v2);
    int getMark(int v);
    void setMark(int v, int val);
    
    void printGraph();
    
    void resetMark();
    void DFSTraverse(MatrixGraph*, int);
    int visitedSum();
};

#endif //GRAPH_MATRIXGRAPH_H
