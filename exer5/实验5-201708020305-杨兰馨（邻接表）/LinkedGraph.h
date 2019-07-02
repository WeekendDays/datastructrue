#ifndef GRAPH_LINKEDGRAPH_H
#define GRAPH_LINKEDGRAPH_H

#define VISITED 1
#define UNVISITED 0

#include<iostream>

#include "Graph.h"
#include "llist.cpp"
#include "Queue.h"
#include "AQueue.h"

#include <algorithm>
using namespace std;

class Edge{
	private:
		int vert;
		int wt;
	public:
		Edge(){
			vert = -1;
			wt = -1;
		}
		Edge(int v,int w){
			vert = v;
			wt = w;
		}
		int vertex(){
			return vert;
		}
		int weight(){
			return wt;
		}
};

class LinkedGraph : public Graph {
private:
    LList<Edge>** vertex;
    int numVertex;
    int numEdge;
    int* mark;
    bool undirected;

    void Init(int);
public:
    explicit LinkedGraph(int n);
    ~LinkedGraph();

    int n() ;
    int e() ;

    int first(int v);
    int next(int v, int w);
    
    void setType(bool flag);
    bool getType();
    
    void setEdge(int v1, int v2, int wght);
    void deleteEdge(int v1, int v2);
    bool isEdge(int i, int j);
    
    int getWeight(int v1, int v2);
    int getMark(int v);
    void setMark(int v, int val);
    
    void printGraph();
    
    void resetMark();
    void DFSTraverse(LinkedGraph* m, int v);
    void BFSTraverse(LinkedGraph* m, int strat, AQueue* Q);
};
#endif //GRAPH_LINKEDGRAPH_H
