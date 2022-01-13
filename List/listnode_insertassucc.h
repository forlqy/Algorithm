#pragma once
template <typename T>
ListNodePosi<T> ListNode<T>::insertAsSucc(T const& e) {
	ListNodePosi<T> x = new ListNode(e, this, succ);//创建新节点
	succ->pred = x; succ = x;//设置逆向链接
	return x;//返回新节点位置
}