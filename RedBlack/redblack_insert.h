#include "redblack.h"
template<typename T> BinNodePosi<T> RedBlack<T>::insert(const T& e){//将e插入红黑树
    BinNodePosi<T>& x = this->search(e); if(x) return x;//确认目标不存在(留意_hot的设置)
    x = new BinNode<T>(e, this->_hot, nullptr, nullptr, 0); this->_size++;//创建红节点x:以_hot为父，黑高度0
    BinNodePosi<T> xOld = x; solveDoubleRed(x); return xOld;//双红修正后即可返回
}//无论e是否存在于原树，返回时总有x->data == e