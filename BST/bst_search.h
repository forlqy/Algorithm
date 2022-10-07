#include "bst.h"
template<typename T> BinNodePosi<T>& BST<T>::search(const T& e){//在BST查找关键码e
    if(!this->_root || e == this->_root->data){_hot = nullptr; return this->_root;}//空树，或恰在树根命中
    for(_hot = this->_root; ;){//否则，自顶向下
        BinNodePosi<T>& v = (e < _hot->data) ? _hot->lc : _hot->rc;//确认方向，深入一层
        if(!v || e == v->data) return v; _hot = v;//一旦命中或抵达叶子，随即返回
    }//返回目标节点位置的引用，以便后续插入，删除操作
}//无论命中或失败，_hot均指向v之父亲(v为根时，hot为nullptr)