#include "BinTree.h"
template<typename T>//删除二叉树中位置x处的节点和其后代，返回被删除节点的数值
int BinTree<T>::remove(BinNodePosi<T> x){//assert:x为二叉树合法位置
    FromParentTo(*x) = nullptr;//切断来自父节点的指针
    updateHeightAbove(x->parent);//更新祖先高度
    int n = removeAt(x); _size -= n; return n;//删除子树x，更新规模，返回删除节点总数
}

template<typename T>
static int removeAt(BinNodePosi<T> x){
    if(!x) return 0;//递归基：空树
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);//递归释放左,右子树
    release(x->data); release(x); return n;//释放被摘除节点，并返回删除节点总数，release释放复杂结构(delete)
}