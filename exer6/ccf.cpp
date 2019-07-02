#define VISITED 1
#define UNVISITED 0 
#include<iostream>
#include<vector>
using namespace std;
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
	virtual void setEdge(int v1, int v2) = 0;//Ϊ��(v1,v2)����Ȩֵ  
    virtual int getMark(int v) = 0;//ȡ�ö���ı�־λ 
    virtual void setMark(int v, int val) = 0;//���ö���ı�־λ 
};
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
    int n();//���ض������ 
    int e();//���رߵĸ��� 
    int first(int v);
    int next(int v, int w);
    void setType(bool flag);//����ͼ������ 
    bool getType();//��ȡͼ������
    void setEdge(int v1, int v2);
    int getMark(int v);
    void setMark(int v, int val);
    void resetMark();
    void DFSTraverse(MatrixGraph*, int);
};
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
    delete [] mark;//���ն�̬�����ڴ� 
    for (int i = 0; i < numVertex; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
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
    return numVertex; // ���û���ھӷ��ؽڵ���
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

void MatrixGraph::setEdge(int v1, int v2) {
        if (matrix[v1][v2] == 0) {
            numEdge++;
        }
        matrix[v1][v2] = 1;
        if(undirected){
        	matrix[v2][v1] = 1;
		}
}

int MatrixGraph::getMark(int v) {
    return mark[v];
}

void MatrixGraph::setMark(int v, int val) {
    mark[v] = val;
}

void MatrixGraph::resetMark(){
	for(int i = 0; i < numVertex; i++){
		mark[i]=UNVISITED;
	}
}

void MatrixGraph::DFSTraverse(MatrixGraph* m, int v) {
    //cout << v << ' ';
    m->setMark(v, VISITED);
    for (int w = m->first(v); w < m->numVertex; w = m->next(v, w)) {
        if (m->getMark(w) == UNVISITED) {
            DFSTraverse(m, w);
        }
    }
}
int vt[101][101];
int main()
{
	bool flag = 0;//ȷ����ͼΪ����ͼ 
	int N,M;
	cin>>N>>M;
//	int** vt = new int*[N];
//	for(int i=0;i<N;i++){
//		vt[i] = new int[N];
//	}
	MatrixGraph ma(N);
	ma.setType(flag);
	int v1,v2,w;
	for(int i=0;i<M;i++)
	{
		cin>>v1>>v2;
		ma.setEdge(v1-1,v2-1);
	}
	int count=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			ma.DFSTraverse(&ma,j);
			vt[i][j]=ma.getMark(i);
			ma.resetMark();
		}
	}
	for(int i=0;i<N;i++)
	{
		int sum=0;
		for(int j=0;j<N;j++)
		{
			if(vt[i][j]==0&&vt[j][i]==0) break;
			else if(vt[i][j]==1||vt[j][i]==1) sum++;
		}
		if(sum==ma.n()) count++;
	}
	cout<<count<<endl;
//	for(int i=0;i<N;i++)
//    delete []vt[i];
//    delete []vt;
	return 0;
}
