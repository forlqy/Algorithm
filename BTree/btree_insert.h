#include "btree.h"
#include <cstddef>
#include <sys/types.h>
template<typename T> bool BTree<T>::insert(const T& e){//将关键码e插入B-树
    BTNodePosi<T> v = search(e); if(v) return false;//确认目标节点不存在
    Rank r = _hot->key.search(e);//在节点_hot的有序关键码向量中查找合适的插入位置
    _hot->key.insert(r + 1, e);//将新关键码插至对应位置
    _hot->child.insert(r + 2, nullptr);//创建空子树指针
    _size++;//更新全树规模
    solveOverflow(_hot);//如有必要，分裂
    return true;//插入成功
}