#pragma once
using VStatus = enum {UNDISCOVERED, DISCOVERED, VISITED};//顶点状态
using EType = enum{UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD};//边在遍历树中所属的类型

template <typename Tv, typename Te>//顶点类型，边类型
class Graph {//Graph模板类
private:
	void reset() {//所有顶点，边的辅助信息复位
		for (int i = 0; i < n; i++) {
			status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;//状态，时间标签
			parent(i) = -1; priority(i) = INT_MAX;//(在遍历树中的)父节点，优先级数
			for (int j = 0; j < n; j++)//所有边的
				if (exists(i, j)) type(i, j) = UNDETERMINED;//类型
		}
	}
	void BFS(int, int&);//(连通域)广度优先搜索算法
	void DFS(int, int&);//...深度优先搜索算法
	void BCC(int, int&, Stack<int>&);//(连通域)基于DFS的双连通分量分解算法
	bool TSort(int, int&, Stack<Tv>*);//...基于DFS拓扑排序算法
	template <typename PU> void PFS(int, PU);//...优先级搜索框架
public:
//顶点
	int n;//顶点总数
	virtual int insert(Tv const&) = 0;//插入顶点，返回编号
	virtual Tv remove(int) = 0;//删除顶点及其关联边，返回该顶点信息
	virtual Tv& vertex(int) = 0;//顶点v的数据（该顶点的确存在）
	virtual int inDegree(int) = 0;//入度
	virtual int outDegree(int) = 0;//出度
	virtual int firstNbr(int) = 0;//v的首个邻接顶点
	virtual int nextNbr(int, int) = 0;//v相当于顶点j的下一邻接顶点
	virtual VStatus& status(int) = 0;//v的状态
	virtual int& dTime(int) = 0;//时间标签dTime
	virtual int& fTime(int) = 0;//
	virtual int& parent(int) = 0;//v在遍历树中的父亲
	virtual int& priority(int) = 0;//v在遍历树中的优先级数
//边：约定无向边统一转化为方向互逆的一对有向边，从而将无向图视为有向图的特例
	int e;//边总数
	virtual bool exists(int, int) = 0;//边(v, u)是否存在
	virtual void insert(Te const&, int, int, int) = 0;//在顶点v与u之间插入权重为w的边e
	virtual Te remove(int, int) = 0;//删除顶点v,u间的边e,返回该边信息
	virtual EType& type(int, int) = 0;//边(v, u)的类型
	virtual Te& edge(int, int) = 0;//边v,u的数据
	virtual int& weight(int, int) = 0;//边v,u的权重
//算法
	void bfs(int);//广度优先搜索
	void dfs(int);//深度优先搜索
	void bcc(int);//基于dfs的双连通分量分解算法
	Stack<Tv>* tSort(int);//基于dfs拓扑排序算法
	void prim(int);//最小支撑树算法
	void dijkstra(int);//最短路径算法
	template <typename PU> void pfs(int, PU);//...优先级搜索框架
};