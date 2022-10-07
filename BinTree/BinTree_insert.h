#include "BinTree.h"
template<typename T> BinNodePosi<T> BinTree<T>::insert(T const& e)
{_size = 1; return _root = new BinNode<T> (e);}//将e当作根节点插入空二叉树

template<typename T> BinNodePosi<T> BinTree<T>::insert(T const& e, BinNodePosi<T> x)
{_size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc;}//e插入为x的左孩子

template<typename T> BinNodePosi<T> BinTree<T>::insert(BinNodePosi<T> x, T const& e)
{_size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc;}//插入为右孩子