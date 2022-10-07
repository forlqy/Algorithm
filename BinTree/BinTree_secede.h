#include "BinTree.h"
#include <type_traits>
template<typename T>//二叉树子树分离算法:将子树x从当前树摘除，将其封装为一颗独立子树返回
BinTree<T>* BinTree<T>::secede(BinNodePosi<T> x){//assert:合法
    FromParentTo(*x) = nullptr;//切段来自父节点的指针
    updateHeightAbove(x->parent);//更新原树中所有祖先的高度
    BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = nullptr;//新树以x为根
    S->_size = x->size(); _size -= S->_size; return S;//更新规模，返回分离出的子树
}