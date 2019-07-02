#ifndef GRAPH
#define GRAPH
#define VISITED 1
#define UNVISITED 0 //定义了节点访问与未访问的两种状态
#define INFINITY 2147483647 //4字节有符号整型数最大值

#include <iostream>

class Graph {
public:
    Graph() {}
    ~Graph() {} 

    virtual void Init(int n) = 0;
    virtual int n() = 0;//返回顶点的值 
    virtual int e() = 0;//返回边的值 
    virtual int first(int v) = 0;//返回顶点v的第一个邻居 
    virtual int next(int v, int w) = 0;//返回在w之后的邻居 
    virtual void setType(bool flag) = 0;//设置图的类型 
    virtual bool getType() = 0;//获取图的类型
	//virtual int locateVex(int u) = 0;//找到值为u的顶点的位置v
	//virtual int getVex(int v) = 0;//返回v位置的顶点的值
	//virtual void putVex(int v,int value) = 0;//给v位置的顶点赋值value 
	virtual void setEdge(int v1, int v2) = 0;//为边(v1,v2)设置权值 
    virtual void deleteEdge(int v1, int v2) = 0;
    virtual bool isEdge(int i, int j) = 0;//判断边(i,j)是否在图中 
    //virtual int getWeight(int v1, int v2) = 0;//返回边的权值 
    virtual int getMark(int v) = 0;//取得顶点的标志位 
    virtual void setMark(int v, int val) = 0;//设置顶点的标志位 
    virtual void printGraph() = 0;//遍历图 
};


#endif //GRAPH_GRAPH_H
