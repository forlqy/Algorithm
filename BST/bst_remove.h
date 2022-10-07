#include "bst.h"
template<typename T> bool BST<T>::remove(const T& e){//删除关键码e
    BinNodePosi<T>& x = search(e); if(!x) return false;//确认目标存在
    removeAt(x, _hot); BST<T>::_size--;//实施删除
    this->updateHeightAbove(_hot);//更新_hot及其历代祖先高度
    return true;//删除成功
}