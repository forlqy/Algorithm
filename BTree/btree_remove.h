#include "btree.h"
template<typename T> bool BTree<T>::remove(const T& e){//B-树删除关键码e
    BTNodePosi<T> v = search(e); if(!v) return false;//确认关键码存在
    Rank r = v->key.search(e);//确定目标关键码在节点v中的秩(由上，必合法)
    if(v->child[0]){//若v非叶子，则e的后继必属于某叶节点
        BTNodePosi<T> u = v->child[r + 1];//在右子树中一直向左，即可
        while(u->child[0]) u = u->child[0];//找出e的后继
        v->key[r] = u->key[0]; v = u; r = 0;//并与之交换位置
    }//至此，v必然位于最底层，且其中第r个关键码就是待删除者
    v->key.remove(r); v->child.remove(r + 1); _size--;//删除e，以及其下两个外部节点之一
    solveUnderflow(v);//如有必要，旋转或合并
    return true;
}