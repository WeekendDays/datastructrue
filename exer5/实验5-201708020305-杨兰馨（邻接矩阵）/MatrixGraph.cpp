#include "MatrixGraph.h"
#include<iostream>
using namespace std;

void MatrixGraph::Init(int n) {
    numVertex = n;
    numEdge = 0;
    
    mark = new int[n];
    for (int i = 0; i < n; i++) {
        mark[i] = UNVISITED;
    }
    
    matrix = (int **) new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

MatrixGraph::MatrixGraph(int n) {
    Init(n);
}

MatrixGraph::~MatrixGraph() {
    delete [] mark;//回收动态分配内存 
    for (int i = 0; i < numVertex; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void MatrixGraph::cclear(){
	delete [] mark;
	mark=NULL;//释放后置空 
	for(int i=0;i<numVertex;i++) 
	delete [] matrix[i];
	delete [] matrix;
	matrix=NULL;//释放后置空 

}

int MatrixGraph::n() {
    return numVertex;
}

int MatrixGraph::e() {
    return numEdge;
}

int MatrixGraph::first(int v) {
    for (int i = 0; i < numVertex; i++) {
        if (matrix[v][i] != 0) {
            return i;
        }
    }
    return numVertex; // 如果没有邻居返回节点数
}

int MatrixGraph::next(int v, int w) {
    for (int i = w + 1; i < numVertex; i++) {
        if (matrix[v][i] != 0) {
            return i;
        }
    }
    return numVertex;
}

void MatrixGraph::setType(bool flag){
	undirected = flag;
}

bool MatrixGraph::getType(){
	return undirected;
}

void MatrixGraph::setEdge(int v1, int v2, int wt) {
	try {
        if (wt <= 0) {
            throw "Illegal weight value";
        }
        if (matrix[v1][v2] == 0) {
            numEdge++;
        }
        matrix[v1][v2] = wt;
        if(undirected){
        	matrix[v2][v1] = wt;
		}
    }
    catch (const char* str) {
        cerr << str << endl;
    }
}

void MatrixGraph::deleteEdge(int v1, int v2) {
    if (matrix[v1][v2] != 0) {
        numEdge--;
    }
    matrix[v1][v2] = 0;
    if(undirected){
        matrix[v2][v1] = 0;
	}
}

bool MatrixGraph::isEdge(int i, int j) {
    return matrix[i][j] != 0;
}

int MatrixGraph::getWeight(int v1, int v2) {
    return matrix[v1][v2];
}

int MatrixGraph::getMark(int v) {
    return mark[v];
}

void MatrixGraph::setMark(int v, int val) {
    mark[v] = val;
}

void MatrixGraph::printGraph() {
    cout << "\t|\t";
    for (int i = 0; i < numVertex; i++) {
        cout << i << '\t';
    }
    cout << endl;
    for (int i = 0; i < numVertex + 2; i++) {
        cout << "————";
    }
    cout << endl;
    for (int i = 0; i < numVertex; i++) {
        cout << i << "\t|\t";
        for (int j = 0; j < numVertex; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}

void MatrixGraph::resetMark(){
	for(int i = 0; i < numVertex; i++){
		mark[i]=UNVISITED;
	}
}

void MatrixGraph::DFSTraverse(MatrixGraph* m, int v) {
    cout << v << ' ';
    m->setMark(v, VISITED);
    for (int w = m->first(v); w < m->numVertex; w = m->next(v, w)) {
        if (m->getMark(w) == UNVISITED) {
            DFSTraverse(m, w);
        }
    }
}

void MatrixGraph::BFSTraverse(MatrixGraph* m,int start,AQueue* Q){
	Q->enqueue(start);
	m->setMark(start,VISITED);
	while(Q->length())
	{
		int v=Q->dequeue();
		cout<<v<<' ';
		for(int w=m->first(v);w<m->n();w=m->next(v,w))
		{
			if(m->getMark(w)==UNVISITED)
			{
				m->setMark(w,VISITED);
				Q->enqueue(w);
			}
		}
	}
}
