#pragma once
template <typename T>
T List<T>::remove(ListNodePosi<T> p) {//ɾ���Ϸ��ڵ�p����������ֵ
	T e = p->data;//���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
	p->pred->succ = p->succ; p->succ->pred = p->pred;//��̣�ǰ��
	delete p; _size--;//�ͷŽڵ㣬���¹�ģ
	return e;
}