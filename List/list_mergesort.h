#pragma once
template <typename T>//�б�鲢�����㷨������ʼ��λ��p��n��Ԫ������
void List<T>::mergeSort(ListNodePosi<T>& p, int n) {//valid(p) && rank(p) + n <= size
	if (n < 2)return;//��������Χ�㹻С��ֱ�ӷ���
	int m = n >> 1;//���е�Ϊ��
	ListNodePosi<T> q = p; for (int i = 0; i < m; i++) q = q->succ;//�ҵ������б����
	mergeSort(p, m); mergeSort(q, n - m);//ǰ�����б�ֱ�����
	p = merge(p, m, *this, q, n - m);//�鲢
}//�����p��Ȼָ��鲢������ģ��£����