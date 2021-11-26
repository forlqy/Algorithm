#pragma once
#include "graph.h"
#include "Vector.h"
template <typename Tv>
struct Vertex {//顶点对象（为简化，未完全封装）
	Tv data; int inDegree, outDegree; VStatus status;//数据，出入度数，状态
	int dTime, fTime;//时间标签
	int parent; int priority;//遍历树中的父节点，优先级数
	Vertex(Tv const& d = (Tv)0) : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED), dTime(-1), fTime(-1), parent(-1), priority(INT_MAX){}
	//构造新顶点，暂不考虑权重溢出
};

template <typename Te>
struct Edge{//边对象
	Te data; int weight; EType type;//数据，权重，类型
	Edge(Te const& d, int w) : data(d), weight(w), type(UNDETERMINED) {}//构造
};

template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te> {//基于向量，以邻接矩阵实现的图
private:
	Vector<Vertex<Tv>> V;//顶点集
	Vector<Vector<Edge<Te>*>> E;//边集
public:
	GraphMatrix() { n = e = 0;}//构造
	virtual ~GraphMatrix(){//析构
		for (int j = 0; j < n; j++)//所有动态创建的
			for (int k = 0; k < n; k++)//边记录
				delete E[j][k];//逐条删除
	}
//顶点的基本操作：查询第i个顶点（0<=i<n）
	virtual Tv& Vertex(int i) { return V[i].data;}//数据
	virtual int inDegree(int i) { return V[i].inDegree; }//入度
	virtual int outDegree(int i) { return V[i].outDegree; }//出度
	virtual int firstNbr(int i) { return nextNbr(i, n); }//首个邻接顶点
	virtual int nextNbr(int i, int j) {//（改用邻接表可提高效率）
		while ((-1 < j) && (!exists(i, --j)));//逆向线性试探
		return j;
	}
	virtual VStatus& status(int i) { return V[i].status; }//状态
	virtual int& dTime(int i) { return V[i].dTime; }//时间标签
	virtual int& fTime(int i) { return V[i].fTime; }//
	virtual int& parent(int i) { return V[i].parent; }//遍历树父亲
	virtual int& priority(int i) { return V[i].priority; }//遍历树优先级树
//顶点的动态操作
	virtual int insert(Tv const& vertex) {//插入顶点，返回编号
		for (int j = 0; j < n; j++) E[j].insert(NULL); n++;//各顶点预留一条潜在关联边
		E.insert(Vector<Edge<Te>*>(n, n, (Edge<Te>*) NULL));//创建新顶点对应的边向量
		return V.insert(Vertex<Tv>(vertex));//顶点向量增加一个顶点
	}
	virtual Tv remove(int i) {//删除第i个顶点及其关联边
		for (int j = 0; j < n; j++)//所有出边
			if (exists(i, j)) { delete E[i][j]; V[j].inDegree--; e--; }//逐条删除
		E.remove(i); n--;//删除第i行
		Tv vBak = vertex(i); V.remove(i);//删除顶点i
		for (int j = 0; j < n; j++)//所有入边
			if (Edge<Te>* x = E[j].remove(i)) { delete x; V[j].outDegree--; e--; }//逐条删除
		return vBak;//返回被删除顶点信息
	}
//边的确认操作
	virtual bool exists(int i, int j) {//边i,j是否存在
		return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL;
	}
//边的基本操作：查询顶点i与j之间的联边（存在）
	virtual EType& type(int i, int j) { return E[i][j]->type; }//边类型
	virtual Te& edge(int i, int j) { return E[i][j]->data;}//数据
	virtual int& weight(int i, int j) { return E[i][j]->weight; }//权重
//边的动态操作
	virtual void insert(Te const& edge, int w, int i, int j) {//插入权重为w的边e = (i, j)
		if (exists(i, j))return;//确保该边尚不存在
		E[i][j] = new Edge<Te>(edge, w);//创建新边
		e++; V[i].outDegree++; V[j].inDegree++;//更新边计数与关联顶点的度数
	}
	virtual Te remove(int i, int j) {//删除顶点i,j之间的联边
		Te eBak = edge(i, j); delete E[i][j]; E[i][j] = NULL;//备份后删除边记录
		e--; V[i].outDegree--; V[j].inDegree--;//更新边计数与关联顶点的度数
		return eBak;//返回被删除边的信息
	}
};
