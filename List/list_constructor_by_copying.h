#pragma once
template <typename T>//�����б�����λ��p���n�assert:pΪ�Ϸ�λ�ã���������n-1����̽ڵ㣩
List<T>::List(ListNodePosi<T> p, int n) { copyNodes(p, n); }

template <typename T>//���帴���б�L
List<T>::List(List<T> const& L) { copyNodes(L.first(), L._size); }

template <typename T>//����L���Ե�r�����n�assert: r + n <= L._size)
List<T>::List(List<T> const& L, int r, int n) {
	ListNodePosi<T> p = L.first();
	while (0 < r--) p = p->succ;
	copyNodes(p, n);
}