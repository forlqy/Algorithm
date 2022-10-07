#include "redblack.h"
/*
RedBlack双红调整算法：解决节点x与其父均为红色的问题。分为两大类：
    RR-1:2次颜色翻转，2次黑高度更新，1-2次旋转，不再递归
    RR-2:3次颜色翻转，3次黑高度更新，0次旋转，需要递归
*/
template<typename T> void RedBlack<T>::solveDoubleRed(BinNodePosi<T> x){//x当前必为红
    if(IsRoot(*x))//若已(递归)转至树根，则将其转黑，整树高度也随之递增
        {this->_root->color = RB_BLACK; this->_root->height++; return;}//否则，x的父亲p必存在
    BinNodePosi<T> p = x->parent; if(IsBlack(p)) return;//若p为黑，则可终止调整。否则
    BinNodePosi<T> g = p->parent;//既然p为红，则x的祖父必存在，且必为黑色
    BinNodePosi<T> u = uncle(x);//以下，视x的叔父u的颜色分别处理
    if(IsBlack(u)){//u为黑(含nullptr)时
        if(IsLChild(*x) == IsLChild(*p))//若x与p同侧(即zif-zig或zag-zag),则
            p->color = RB_BLACK;//p由红转黑，x保持红
        else//若x与p异侧(即zig-zag或zag-zig)，则
            x->color = RB_BLACK;//x由红转黑，p保持红
        g->color = RB_RED;//g必定为红
//      以上虽保证总共2次染色，但因增加了判断而得不偿失
//      在旋转后将根置黑，孩子置红，虽需3次染色但效率更高
    BinNodePosi<T> gg = g->parent;//曾祖父(great-grand parent)
    BinNodePosi<T> r = FromParentTo(*g) = this->rotateAt(x);//调整后的子树根节点
    r->parent = gg;//与原曾祖父联接
    }else{//若u为红色
        p->color = RB_BLACK; p->height++;//p由红转黑
        u->color = RB_BLACK; u->height++;//u由红转黑
        g->color = RB_RED;//在B-树中g相当于上交给父节点的关键码，故暂标记为红
        solveDoubleRed(g);//继续调整：若已至树根，接下来的递归会将g转黑(尾递归，可改为迭代)
    }
}