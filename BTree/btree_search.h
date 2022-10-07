#include "btree.h"
template<typename T> BTNodePosi<T> BTree<T>::search(const T& e){//在B-树查找关键码e
    BTNodePosi<T> v = _root; _hot = nullptr;//从根节点出发
    while(v){//逐层查找
        Rank r = v->key.search(e);//在当前节点中，找到不大于e的最大关键码
        if((0 <= r) && (e == v->key[r])) return v;//成功：在当前节点中命中目标关键码
        _hot = v; v = v->child[r + 1];//否则，转入对应子树(_hot指向其父)------需做I/O，最费时间
    }//这里向量内二分查找，但对通常的_m可直接顺序查找
    return nullptr;//失败：最终抵达外部节点
}