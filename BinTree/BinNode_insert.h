#include "BinNode.h"
template <typename T> BinNodePosi<T> BinNode<T>::insertAsLC(T const& e)
{return lc = new BinNode(e, this);}//将e作为当前节点的左孩子

template <typename T> BinNodePosi<T> BinNode<T>::insertAsRC(T const& e)
{return rc = new BinNode(e, this);}