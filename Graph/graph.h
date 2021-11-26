#pragma once
using VStatus = enum {UNDISCOVERED, DISCOVERED, VISITED};//����״̬
using EType = enum{UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD};//���ڱ�����������������

template <typename Tv, typename Te>//�������ͣ�������
class Graph {//Graphģ����
private:
	void reset() {//���ж��㣬�ߵĸ�����Ϣ��λ
		for (int i = 0; i < n; i++) {
			status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;//״̬��ʱ���ǩ
			parent(i) = -1; priority(i) = INT_MAX;//(�ڱ������е�)���ڵ㣬���ȼ���
			for (int j = 0; j < n; j++)//���бߵ�
				if (exists(i, j)) type(i, j) = UNDETERMINED;//����
		}
	}
	void BFS(int, int&);//(��ͨ��)������������㷨
	void DFS(int, int&);//...������������㷨
	void BCC(int, int&, Stack<int>&);//(��ͨ��)����DFS��˫��ͨ�����ֽ��㷨
	bool TSort(int, int&, Stack<Tv>*);//...����DFS���������㷨
	template <typename PU> void PFS(int, PU);//...���ȼ��������
public:
//����
	int n;//��������
	virtual int insert(Tv const&) = 0;//���붥�㣬���ر��
	virtual Tv remove(int) = 0;//ɾ�����㼰������ߣ����ظö�����Ϣ
	virtual Tv& vertex(int) = 0;//����v�����ݣ��ö����ȷ���ڣ�
	virtual int inDegree(int) = 0;//���
	virtual int outDegree(int) = 0;//����
	virtual int firstNbr(int) = 0;//v���׸��ڽӶ���
	virtual int nextNbr(int, int) = 0;//v�൱�ڶ���j����һ�ڽӶ���
	virtual VStatus& status(int) = 0;//v��״̬
	virtual int& dTime(int) = 0;//ʱ���ǩdTime
	virtual int& fTime(int) = 0;//
	virtual int& parent(int) = 0;//v�ڱ������еĸ���
	virtual int& priority(int) = 0;//v�ڱ������е����ȼ���
//�ߣ�Լ�������ͳһת��Ϊ�������һ������ߣ��Ӷ�������ͼ��Ϊ����ͼ������
	int e;//������
	virtual bool exists(int, int) = 0;//��(v, u)�Ƿ����
	virtual void insert(Te const&, int, int, int) = 0;//�ڶ���v��u֮�����Ȩ��Ϊw�ı�e
	virtual Te remove(int, int) = 0;//ɾ������v,u��ı�e,���ظñ���Ϣ
	virtual EType& type(int, int) = 0;//��(v, u)������
	virtual Te& edge(int, int) = 0;//��v,u������
	virtual int& weight(int, int) = 0;//��v,u��Ȩ��
//�㷨
	void bfs(int);//�����������
	void dfs(int);//�����������
	void bcc(int);//����dfs��˫��ͨ�����ֽ��㷨
	Stack<Tv>* tSort(int);//����dfs���������㷨
	void prim(int);//��С֧�����㷨
	void dijkstra(int);//���·���㷨
	template <typename PU> void pfs(int, PU);//...���ȼ��������
};