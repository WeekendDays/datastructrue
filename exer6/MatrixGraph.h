#ifndef GRAPH_MATRIXGRAPH_H
#define GRAPH_MATRIXGRAPH_H
#define VISITED 1
#define UNVISITED 0 //定义了节点访问与未访问的两种状态
#include "Graph.h"

class MatrixGraph : public Graph {
private:
    int numVertex;//定义顶点个数 
    int numEdge;//定义边个数 
    int** matrix;//定义二维数组 
    int* mark;//定义顶点数组 
    bool undirected;//true表示无向图 false表示有向图
    void Init(int n) ;//初始化图 

public:
    explicit MatrixGraph(int n);
    ~MatrixGraph();
    void cclear();

    int n();//返回顶点个数 
    int e();//返回边的个数 

    int first(int v);
    int next(int v, int w);
    
    void setType(bool flag);//设置图的类型 
    bool getType();//获取图的类型
	
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
