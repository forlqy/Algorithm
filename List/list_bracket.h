#pragma once
template <typename T>//�����±������[],��ͨ����ֱ�ӷ����б�ڵ㣨Ч�ʵͣ����ã�
T& List<T>::operator[] (Rank r)const {//assert:0 <= r <= size
	ListNodePosi<T> p = first();//���׽ڵ����
	while (0 < r--) p = p->succ;//˳����r���ڵ�
	return p->data;//Ŀ��ڵ㣬������������Ԫ��
}