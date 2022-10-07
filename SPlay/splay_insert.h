#include "splay.h"
template<typename T> BinNodePosi<T> Splay<T>::insert(const T& e){//将e插入伸展树
    if(!this->_root){this->_size = 1; return this->_root = new BinNode<T> (e);}//原树为空
    BinNodePosi<T> t = search(e); if(e == t->data) return t;//目标节点t若存在，伸展至根
    if(t->data < e){//在右侧嫁接
        t->parent = this->_root = new BinNode<T> (e, nullptr, t, t->rc);//lc==t必非空(这里构造函数虽然只指定了四个参数，但不会报错，因为后面的参数有默认初始化的值)
        if(t->rc){t->rc->parent = this->_root; t->rc = nullptr;}//rc或为空
    }else{//在左侧嫁接
        t->parent = this->_root = new BinNode<T> (e, nullptr, t->lc, t);//rc==t必非空
        if(t->lc){t->lc->parent = this->_root; t->lc = nullptr;}//lc或为空
    }
    this->_size++; this->updateHeightAbove(t); return this->_root;//更新规模高度，报告插入成功(update----不重写？)
}//无论e是否存在于原树中，返回时总有_root->data == e