#pragma once
template <typename T>//在有序列表内节点p（可能为trailer）的n个（真）前驱中，找到不大于e的最后者
ListNodePosi<T> List<T>::search(T const& e, int n, ListNodePosi<T> p)const {
//assert: 0 <= n <= rank(p) < _size
	do {
		p = p->pred; n--;//从右向左
	} while ((-1 < n) && (e < p->data));//逐个比较，直至命中或越界
	return p;//返回查找终止的位置
}//失败时，返回区间左边界的前驱（可能是header）--调用者可通过valid()判断成功与否