#include "BinTree.h"
template<typename T>//��S�����ڵ�x�������������������S�����ÿ�
BinNodePosi<T> BinTree<T>::attach(BinTree<T>* &S, BinNodePosi<T> x){//x->lc == nullptr
    if((x->lc = S->_root)) x->lc->parent = x;//����(��ʱ�����ж�Ϊ��ֵ��䣬Ҫ�����ţ���Ȼ����warning)
    _size += S->_size; updateHeightAbove(x);//����ȫ����ģ��x�������ȵĸ߶�
    S->_root = nullptr; S->_size = 0;release(S); S = nullptr; return x;//�ͷ�ԭ�������ؽ���λ��
}

template<typename T>//��S�����ڵ�x�������������������S�����ÿ�
BinNodePosi<T> BinTree<T>::attach(BinNodePosi<T> x, BinTree<T>* &S){
    if((x->rc = S->_root)) x->rc->parent = x;
    _size += S->_size; updateHeightAbove(x);
    S->_root = nullptr; S->_size = 0; release(S); S = nullptr; return x;
}