#include "LinkedGraph.h"

void LinkedGraph::Init(int n) {
    numVertex = n;
    numEdge = 0;
    
    mark = new int[n];
    for (int i = 0; i < n; i++) {
        mark[i] = UNVISITED;
    }
    
    vertex = (LList<Edge>**)new LList<Edge>*[n];
    for (int i = 0; i < n; i++) {
        vertex[i] = new LList<Edge>(1010);
    }
}

LinkedGraph::LinkedGraph(int n) {
    Init(n);
}

LinkedGraph::~LinkedGraph() {
    delete [] mark;
    for (int i = 0; i < numVertex; i++) {
        delete [] vertex[i];
    }
    delete [] vertex;
}

int LinkedGraph::n() {
    return numVertex;
}

int LinkedGraph::e() {
    return numEdge;
}

int LinkedGraph::first(int v) {
    if(vertex[v]->length()==0){
    	return numVertex;
	}
	vertex[v]->moveToStart();
	Edge it=vertex[v]->getValue();
	return it.vertex();
}

int LinkedGraph::next(int v, int w) {
    Edge it;
    if(isEdge(v,w)){
    	if(vertex[v]->currPos()+1 < vertex[v]->length()){
    		vertex[v]->next();
    		it = vertex[v]->getValue();
    		return it.vertex();
		}
	}
    return n();
}

void LinkedGraph::setType(bool flag){
    undirected=flag;
}

bool LinkedGraph::getType(){
	return undirected;
}

void LinkedGraph::setEdge(int v1, int v2, int wt) {
    try {
        if (wt <= 0) {
            throw "Illegal weight value";
        }
        Edge tmp(v2, wt);

        if (isEdge(v1, v2)) {
        	vertex[v1]->remove();
        	vertex[v1]->insert(tmp);
        }
        else {
            numEdge++;
            for(vertex[v1]->moveToStart();
			vertex[v1]->currPos() < vertex[v1]->length();
			vertex[v1]->next()){
				Edge tmp1 = vertex[v1]->getValue();
				if(tmp1.vertex()>v2) break;
			}
        vertex[v1]->insert(tmp);
        if(undirected){
            Edge tmp2(v1,wt);
            for(vertex[v2]->moveToStart();
			vertex[v2]->currPos() < vertex[v2]->length();
			vertex[v2]->next()){
				Edge tmp3=vertex[v2]->getValue();
				if(tmp3.vertex()>v1) break;
			}
			vertex[v2]->insert(tmp2);
			}
        }
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}

void LinkedGraph::deleteEdge(int v1, int v2) {
    if (isEdge(v1, v2)){
    	vertex[v1]->remove();
    	numEdge--;
	}
	if(undirected){
		if(isEdge(v2,v1)){
			vertex[v2]->remove();
			numEdge--;
		}
	}
}

bool LinkedGraph::isEdge(int i, int j) {
    Edge it;
    for(vertex[i]->moveToStart();
	vertex[i]->currPos() < vertex[i]->length();
	vertex[i]->next()){
		Edge temp=vertex[i]->getValue();
		if(temp.vertex()==j) return true;
	}
	return false;
}

int LinkedGraph::getWeight(int v1, int v2) {
    Edge curr;
    if(isEdge(v1,v2)){
    	curr=vertex[v1]->getValue();
    	return curr.weight();
	}
	else return 0;
}

int LinkedGraph::getMark(int v) {
    return mark[v];
}

void LinkedGraph::setMark(int v, int val) {
    mark[v] = val;
}

void LinkedGraph::printGraph() {
    for(int i=0;i<numVertex;i++){
    	cout<<i<<" ";
    	for(vertex[i]->moveToStart();
		vertex[i]->currPos() < vertex[i]->length();
		vertex[i]->next()){
			Edge it=vertex[i]->getValue();
			cout<<"-->"<<it.vertex()<<" ";
		}
		cout<<endl;
	}
}

void LinkedGraph::resetMark(){
	for(int i = 0; i < numVertex; i++){
		mark[i]=UNVISITED;
	}
}

void LinkedGraph::DFSTraverse(LinkedGraph* m, int v) {
    cout << v << ' ';
    m->setMark(v, VISITED);
    for (int w = m->first(v); w < m->n(); w = m->next(v, w)) {
        if (m->getMark(w) == UNVISITED) {
            DFSTraverse(m, w);
        }
    }
}

void LinkedGraph::BFSTraverse(LinkedGraph* m, int start, AQueue* Q){
	Q->enqueue(start);
	m->setMark(start,VISITED);
	while(Q->length())
	{
		int v=Q->dequeue();
		cout<<v<<" ";
		for(int w = m->first(v); w < m->n(); w = m->next(v,w))
		{
			if(m->getMark(w) == UNVISITED)
			{
				m->setMark(w,VISITED);
				Q->enqueue(w);
			}
		}	
	}
}


