#pragma once
template <typename T>
void List<T>::reverse() {//ǰ����
	if (_size < 2) return;
	ListNodePosi<T> p; ListNodePosi<T> q;
	for (p = header, q = p->succ; p != trailer; p = q, q = p->succ)
		p->pred = q;//��ǰ������εߵ����ڵ��ǰ��ָ��
	trailer->pred = NULL;//��������β�ڵ��ǰ��ָ��
	for (p = header, q = p->pred; p != trailer; p = q, q = p->pred)
		q->succ = p;//��ǰ������εߵ����ڵ�ĺ��ָ��
	header->succ = NULL;//��������ͷ�ڵ�ĺ��ָ��
	std::swap(header, trailer);//ͷ��β�ڵ㻥��
}