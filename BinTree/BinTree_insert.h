#include "BinTree.h"
template<typename T> BinNodePosi<T> BinTree<T>::insert(T const& e)
{_size = 1; return _root = new BinNode<T> (e);}//��e�������ڵ����ն�����

template<typename T> BinNodePosi<T> BinTree<T>::insert(T const& e, BinNodePosi<T> x)
{_size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc;}//e����Ϊx������

template<typename T> BinNodePosi<T> BinTree<T>::insert(BinNodePosi<T> x, T const& e)
{_size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc;}//����Ϊ�Һ���