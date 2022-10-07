#include "../Vector/vector.h"
template<typename T> struct BTNode;
template<typename T> using BTNodePosi = BTNode<T>*;//B-树节点位置

template<typename T> struct BTNode{
// 成员(可进一步封装)
    BTNodePosi<T> parent;//父节点
    Vector<T> key;//关键码向量
    Vector<BTNodePosi<T>> child;//孩子向量(总比关键码多一个)
// 构造函数
    BTNode(){parent = nullptr; child.insert(nullptr);}//无关键码节点
    BTNode(T e, BTNodePosi<T> lc = nullptr, BTNodePosi<T> rc = nullptr){
        parent = nullptr; key.insert(e);//作为根节点只有一个关键码，以及
        child.insert(lc); if(lc) lc->parent = this;//左孩子
        child.insert(rc); if(rc) rc->parent = this;//右孩子
    }
};