#pragma once
template <typename T>
List<T>::~List() {//�б�������
	clear(); delete header; delete trailer;//����б��ͷ�ͷ��β�ڱ��ڵ�
}