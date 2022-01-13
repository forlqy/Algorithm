#pragma once
template <typename T>
ListNodePosi<T> List<T>::insertAsFirst(T const& e) {
	_size++; return header->insertAsSucc(e);//e�����׽ڵ����
}

template <typename T>
ListNodePosi<T> List<T>::insertAsLast(T const& e) {
	_size++; return trailer->insertAsPred(e);//e����β�ڵ����
}

template <typename T>
ListNodePosi<T> List<T>::insert(ListNodePosi<T> p, T const& e) {
	_size++; return p->insertAsSucc(e);//e����p�ĺ�̲���
}

template <typename T>
ListNodePosi<T> List<T>::insert(T const& e, ListNodePosi<T> p) {
	_size++; return p->insertAsPred(e);//e����p��ǰ������
}