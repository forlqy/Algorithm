#pragma once
template <typename T>//�������б��ڽڵ�p������Ϊtrailer����n�����棩ǰ���У��ҵ�����e�������
ListNodePosi<T> List<T>::find(T const& e, int n, ListNodePosi<T> p)const {
	while (0 < n--)//(0 <= n <=rank(p) < _size)����p�������n��ǰ������������
		if (e == (p = p->pred)->data) return p;//����ȶԣ�ֱ�����л�ΧԽ��
	return NULL;//pԽ����߽���ζ���䲻��e������ʧ��
}//����NULL