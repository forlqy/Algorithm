#pragma once
template <typename T>
int List<T>::clear() {//����б�
	int oldSize = _size;
	while (0 < _size) remove(header->succ);//����ɾ���׽ڵ㣬ֱ���б���
	return oldSize;
}