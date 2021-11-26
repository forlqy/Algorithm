#pragma once
#include "graph.h"
#include "Vector.h"
template <typename Tv>
struct Vertex {//�������Ϊ�򻯣�δ��ȫ��װ��
	Tv data; int inDegree, outDegree; VStatus status;//���ݣ����������״̬
	int dTime, fTime;//ʱ���ǩ
	int parent; int priority;//�������еĸ��ڵ㣬���ȼ���
	Vertex(Tv const& d = (Tv)0) : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED), dTime(-1), fTime(-1), parent(-1), priority(INT_MAX){}
	//�����¶��㣬�ݲ�����Ȩ�����
};

template <typename Te>
struct Edge{//�߶���
	Te data; int weight; EType type;//���ݣ�Ȩ�أ�����
	Edge(Te const& d, int w) : data(d), weight(w), type(UNDETERMINED) {}//����
};

template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te> {//�������������ڽӾ���ʵ�ֵ�ͼ
private:
	Vector<Vertex<Tv>> V;//���㼯
	Vector<Vector<Edge<Te>*>> E;//�߼�
public:
	GraphMatrix() { n = e = 0;}//����
	virtual ~GraphMatrix(){//����
		for (int j = 0; j < n; j++)//���ж�̬������
			for (int k = 0; k < n; k++)//�߼�¼
				delete E[j][k];//����ɾ��
	}
//����Ļ�����������ѯ��i�����㣨0<=i<n��
	virtual Tv& Vertex(int i) { return V[i].data;}//����
	virtual int inDegree(int i) { return V[i].inDegree; }//���
	virtual int outDegree(int i) { return V[i].outDegree; }//����
	virtual int firstNbr(int i) { return nextNbr(i, n); }//�׸��ڽӶ���
	virtual int nextNbr(int i, int j) {//�������ڽӱ�����Ч�ʣ�
		while ((-1 < j) && (!exists(i, --j)));//����������̽
		return j;
	}
	virtual VStatus& status(int i) { return V[i].status; }//״̬
	virtual int& dTime(int i) { return V[i].dTime; }//ʱ���ǩ
	virtual int& fTime(int i) { return V[i].fTime; }//
	virtual int& parent(int i) { return V[i].parent; }//����������
	virtual int& priority(int i) { return V[i].priority; }//���������ȼ���
//����Ķ�̬����
	virtual int insert(Tv const& vertex) {//���붥�㣬���ر��
		for (int j = 0; j < n; j++) E[j].insert(NULL); n++;//������Ԥ��һ��Ǳ�ڹ�����
		E.insert(Vector<Edge<Te>*>(n, n, (Edge<Te>*) NULL));//�����¶����Ӧ�ı�����
		return V.insert(Vertex<Tv>(vertex));//������������һ������
	}
	virtual Tv remove(int i) {//ɾ����i�����㼰�������
		for (int j = 0; j < n; j++)//���г���
			if (exists(i, j)) { delete E[i][j]; V[j].inDegree--; e--; }//����ɾ��
		E.remove(i); n--;//ɾ����i��
		Tv vBak = vertex(i); V.remove(i);//ɾ������i
		for (int j = 0; j < n; j++)//�������
			if (Edge<Te>* x = E[j].remove(i)) { delete x; V[j].outDegree--; e--; }//����ɾ��
		return vBak;//���ر�ɾ��������Ϣ
	}
//�ߵ�ȷ�ϲ���
	virtual bool exists(int i, int j) {//��i,j�Ƿ����
		return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL;
	}
//�ߵĻ�����������ѯ����i��j֮������ߣ����ڣ�
	virtual EType& type(int i, int j) { return E[i][j]->type; }//������
	virtual Te& edge(int i, int j) { return E[i][j]->data;}//����
	virtual int& weight(int i, int j) { return E[i][j]->weight; }//Ȩ��
//�ߵĶ�̬����
	virtual void insert(Te const& edge, int w, int i, int j) {//����Ȩ��Ϊw�ı�e = (i, j)
		if (exists(i, j))return;//ȷ���ñ��в�����
		E[i][j] = new Edge<Te>(edge, w);//�����±�
		e++; V[i].outDegree++; V[j].inDegree++;//���±߼������������Ķ���
	}
	virtual Te remove(int i, int j) {//ɾ������i,j֮�������
		Te eBak = edge(i, j); delete E[i][j]; E[i][j] = NULL;//���ݺ�ɾ���߼�¼
		e--; V[i].outDegree--; V[j].inDegree--;//���±߼������������Ķ���
		return eBak;//���ر�ɾ���ߵ���Ϣ
	}
};
