#include "btree.h"

template<typename T>//关键码若插入后节点上溢，则做节点分裂处理
void BTree<T>::solveOverflow(BTNodePosi<T> v){
    while(_m <= v->key.size()){//除非当前节点并未上溢
        Rank s = _m >> 1;//轴点(此时应有_m = key.size() = child.size() - 1);_m / 2
        BTNodePosi<T> u = new BTNode<T>();//注意：新节点已有一个空孩子
        for(Rank j = 0; j < _m - s - 1; j++){//v右侧_m-s-1个孩子及关键码分裂为右侧节点u
            u->child.insert(j, v->child.remove(s + 1));//逐个移动效率低
            u->key.insert(j, v->key.remove(s + 1));//此策略可改进
        }
        u->child[_m - s - 1] = v->child.remove(s + 1);//移动v最靠右的孩子
        if(u->child[0])//若u的孩子们非空,则
            for(Rank j = 0; j < _m - s; j++)//令它们的父节点统一
                u->child[j]->parent = u;//指向u
        BTNodePosi<T> p = v->parent;//v当前的父节点p
        if(!p){_root = p = new BTNode<T>(); p->child[0] = v; v->parent = p;}//若p空则创建之
        Rank r = 1 + p->key.search(v->key[0]);//p中指向v的指针的秩
        p->key.insert(r, v->key.remove(s));//轴点关键码上升
        p->child.insert(r + 1, u); u->parent = p;//新节点u与父节点p互联
        v = p;//上升一层，如有必要继续分裂(至多O(logn)层)
    }//while
}//solveOverflow