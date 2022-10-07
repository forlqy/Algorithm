#include "bst.h"
/*子树根节点与上层节点之间的双向联接，均须由上层调用者完成；可用于AVL和RedBlack的局部平衡调整*/
template<typename T> BinNodePosi<T> BST<T>::connect34(
    BinNodePosi<T> a, BinNodePosi<T> b, BinNodePosi<T> c,
    BinNodePosi<T> T0, BinNodePosi<T> T1, BinNodePosi<T> T2, BinNodePosi<T> T3
){
    a->lc = T0; if(T0) T0->parent = a;
    a->rc = T1; if(T1) T1->parent = a; updateHeight(a);
    c->lc = T2; if(T2) T2->parent = c;
    c->rc = T3; if(T3) T3->height = c; updateHeight(c);
    b->lc = a; a->parent = b;
    b->rc = c; c->parent = b; updateHeight(b);
    return b;//该子树新的根节点
}