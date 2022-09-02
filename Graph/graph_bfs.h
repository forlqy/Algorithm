#pragma once
#include "queue.h"
#include "graph.h"
template <typename Tv, typename Te>//BFS�㷨(ȫͼ)
void Graph<Tv, Te>::bfs(int s) {//assert: 0 <= s < n
	reset(); int clock = 0; int v = s;//��ʼ��
	do{//��һ������ж���
		if (UNDISCOVERED == status(v))//һ��������δ���ֵĶ���
			BFS(v, clock);//���Ӹö����������һ��BFS
	} while (s != (v = ((v + 1) % n)));//����ż�飬���ز�©
}

template <typename Tv, typename Te>//(������ͨ��)
void Graph<Tv, Te>::BFS(int v, int& clock) {
	Queue<int> Q;//���븨������
	status(v) = DISCOVERED; Q.enqueue(v);//��ʼ�����
	while (!Q.empty()) {
		int v = Q.dequeue(); dTime(v) = ++clock;//ȡ�����׶���v
		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))//ö��v�������ھ�u
			if (UNDISCOVERED == status(u)) {//��u��δ������
				status = DISCOVERED; Q.enqueue(u);//���ָö���
				type(v, u) = TREE; parent(u) = v;//����������չ֧����
			}
			else {//�ѱ����֣��������ѷ������
				type(v, u) = CROSS;//��(v, u)�����ڿ��
			}
		status(v) = VISITED;//���ˣ���ǰ����������
	}
}