#pragma once
template <typename T>//重载下标操作符[],以通过秩直接访问列表节点（效率低，慎用）
T& List<T>::operator[] (Rank r)const {//assert:0 <= r <= size
	ListNodePosi<T> p = first();//从首节点出发
	while (0 < r--) p = p->succ;//顺数第r个节点
	return p->data;//目标节点，返回其中所存元素
}