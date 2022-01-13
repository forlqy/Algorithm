#pragma once
template <typename T>
int List<T>::deduplicate() {//����ȥ��
	int oldSize = _size; ListNodePosi<T> p = first();
	for (Rank r = 0; p != trailer; p = p->succ)//O(n)
		if (ListNodePosi<T> q = find(p->data, r, p))
			remove(q);//��ʱq��p��ͬ��ɾ��ǰ�߸�����
		else r++;//rΪ����ǰ׺�ĳ���
	return oldSize - _size;//ɾ��Ԫ������
}