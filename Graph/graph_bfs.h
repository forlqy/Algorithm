#pragma once
#include "queue.h"
#include "graph.h"
template <typename Tv, typename Te>//BFS算法(全图)
void Graph<Tv, Te>::bfs(int s) {//assert: 0 <= s < n
	reset(); int clock = 0; int v = s;//初始化
	do{//逐一检查所有顶点
		if (UNDISCOVERED == status(v))//一旦遇到尚未发现的顶点
			BFS(v, clock);//即从该顶点出发启动一次BFS
	} while (s != (v = ((v + 1) % n)));//按序号检查，不重不漏
}

template <typename Tv, typename Te>//(单个连通域)
void Graph<Tv, Te>::BFS(int v, int& clock) {
	Queue<int> Q;//引入辅助队列
	status(v) = DISCOVERED; Q.enqueue(v);//初始化起点
	while (!Q.empty()) {
		int v = Q.dequeue(); dTime(v) = ++clock;//取出队首顶点v
		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))//枚举v的所有邻居u
			if (UNDISCOVERED == status(u)) {//若u尚未被发现
				status = DISCOVERED; Q.enqueue(u);//发现该顶点
				type(v, u) = TREE; parent(u) = v;//引入树边拓展支撑树
			}
			else {//已被发现，或甚至已访问完毕
				type(v, u) = CROSS;//将(v, u)归类于跨边
			}
		status(v) = VISITED;//至此，当前顶点访问完毕
	}
}