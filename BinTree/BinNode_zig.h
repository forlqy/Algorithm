#include "BinNode.h"
template <typename T>
BinNodePosi<T> BinNode<T>::zig(){//˳ʱ����ת
    BinNodePosi<T> lChild = lc;
    lChild->parent = this->parent;
    if (lChild->parent)
        ((this == lChild->parent->rc) ? lChild->parent->rc : lChild->parent->lc) = lChild;
    lc = lChild->rc;
    if (lc) lc->parent = this;
    lChild->rc = this; this->parent = lChild;
//update heights()
    height = 1 + max(stature(lc), stature(rc));
    lChild->height = 1 + max(stature(lChild->rc), stature(lChild->lc));
    for (BinNodePosi<T> x = lChild->parent; x; x = x->parent)
        if (HeightUpdated(*x))
            break;
        else
            x->height = 1 + max(stature(x->lc), stature(x->rc));
    return lChild;
}