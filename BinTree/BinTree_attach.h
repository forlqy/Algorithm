#include "BinTree.h"
template<typename T>//将S当作节点x的左子树接入二叉树，S本身置空
BinNodePosi<T> BinTree<T>::attach(BinTree<T>* &S, BinNodePosi<T> x){//x->lc == nullptr
    if((x->lc = S->_root)) x->lc->parent = x;//接入(此时条件判断为赋值语句，要加括号，不然会有warning)
    _size += S->_size; updateHeightAbove(x);//更新全树规模与x所有祖先的高度
    S->_root = nullptr; S->_size = 0;release(S); S = nullptr; return x;//释放原树，返回接入位置
}

template<typename T>//将S当作节点x的右子树接入二叉树，S本身置空
BinNodePosi<T> BinTree<T>::attach(BinNodePosi<T> x, BinTree<T>* &S){
    if((x->rc = S->_root)) x->rc->parent = x;
    _size += S->_size; updateHeightAbove(x);
    S->_root = nullptr; S->_size = 0; release(S); S = nullptr; return x;
}