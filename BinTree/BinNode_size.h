#include "BinNode.h"
template <typename T>
int BinNode<T>::size(){//统计当前节点后代总数，即以其为根的子树规模
    int s = 1;//计入自身（根）
    if (lc) s += lc->size();//递归计入左子树规模
    if (rc) s += rc->size();//递归计入右子树规模
    return s;
}