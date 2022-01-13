#pragma once
template <typename T>
ListNodePosi<T> List<T>::insertAsFirst(T const& e) {
	_size++; return header->insertAsSucc(e);//e当作首节点插入
}

template <typename T>
ListNodePosi<T> List<T>::insertAsLast(T const& e) {
	_size++; return trailer->insertAsPred(e);//e当作尾节点插入
}

template <typename T>
ListNodePosi<T> List<T>::insert(ListNodePosi<T> p, T const& e) {
	_size++; return p->insertAsSucc(e);//e当作p的后继插入
}

template <typename T>
ListNodePosi<T> List<T>::insert(T const& e, ListNodePosi<T> p) {
	_size++; return p->insertAsPred(e);//e当作p的前驱插入
}