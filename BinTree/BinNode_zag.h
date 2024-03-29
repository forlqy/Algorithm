#include "BinNode.h"
template <typename T>
BinNodePosi<T> BinNode<T>::zag(){//��ʱ����ת
    BinNodePosi<T> rChild = rc;
    rChild->parent = this->parent;
    if(rChild->parent)
        ((this == rChild->parent->lc) ? rChild->parent->lc : rChild->parent->rc) = rChild;
    rc = rChild->lc;
    if(rc) rc->parent=this;
    rChild->lc = this; this->parent = rChild;
//update heights
    height = 1 + max(stature(lc), stature(rc));
    rChild->height = 1 + max(stature(rChild->lc), stature(rChild->rc));
    for (BinNodePosi<T> x = rChild->parent; x; x = x->parent)
        if(HeightUpdated(*x))
            break;
        else
            x->height = 1 + max(stature(x->lc), stature(x->rc));
    return rChild;
}