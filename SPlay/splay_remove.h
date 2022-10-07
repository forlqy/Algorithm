#include "splay.h"
template<typename T> bool Splay<T>::remove(const T& e){//从伸展树删除e
    if(!this->_root || (e != search(e)->data)) return false;//若目标存在，则伸展至根
    BinNodePosi<T> L = this->_root->lc, R = this->_root->rc; release(this->_root);//记下左，右子树LR后，释放之
    if(!R){//若R空，则
        if(L) L->parent = nullptr; this->_root = L;//L即是余树
    }else{//否则
        this->_root = R; R->parent = nullptr; search(e);//在R中再次查找e：注定失败，但其中最小节点必
        if(L) L->parent = this->_root; this->_root->lc = L;//伸展至根(且无左孩子)，故可令其以L作为左子树
    }
    if(--(this->_size)) this->updateHeight(this->_root); return true;//更新规模和树高(重写？)，报告删除成功
}