#pragma once
template <typename T>
void List<T>::init() {
	header = new ListNode<T>;//����ͷ�ڱ��ڵ�
	trailer = new ListNode<T>;//����β�ڱ�
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;//��¼��ģ
}