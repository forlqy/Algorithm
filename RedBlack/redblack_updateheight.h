#include "redblack.h"
template<typename T> int RedBlack<T>::updateHeight(BinNodePosi<T> x){//更新节点高度
    return x->height = IsBlack(x) + max(stature(x->lc), stature(x->rc));//孩子黑高度通常相等，除非出现双黑
}