#include "splay.h"
template<typename T> BinNodePosi<T>& Splay<T>::search(const T& e){//在伸展树查找e
    BinNodePosi<T> p = BST<T>::search(e);
    this->_root = splay(p ? p : this->_hot);//将最后一个被访问的节点伸展至根
    return this->_root;
}//与其他BST不同，无论查找成功与否，_root都指向最后被访问的节点