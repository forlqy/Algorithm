#pragma once
template <typename T>//�������б��ڽڵ�p������Ϊtrailer����n�����棩ǰ���У��ҵ�������e�������
ListNodePosi<T> List<T>::search(T const& e, int n, ListNodePosi<T> p)const {
//assert: 0 <= n <= rank(p) < _size
	do {
		p = p->pred; n--;//��������
	} while ((-1 < n) && (e < p->data));//����Ƚϣ�ֱ�����л�Խ��
	return p;//���ز�����ֹ��λ��
}//ʧ��ʱ������������߽��ǰ����������header��--�����߿�ͨ��valid()�жϳɹ����