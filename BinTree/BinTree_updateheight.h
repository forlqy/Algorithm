#include "BinTree.h"
template<typename T> int BinTree<T>::updateHeight(BinNodePosi<T> x)//���½ڵ�x�߶�
{return x->height = 1 + max(stature(x->lc), stature(x->rc));}//��������������죬��������Ϊvirtual

template<typename T> void BinTree<T>::updateHeightAbove(BinNodePosi<T> x)//���¸߶�
{while(x){updateHeight(x); x = x->parent;}}//��x�����������������ȡ�