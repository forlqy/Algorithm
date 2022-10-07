#include "BinNode.h"
template <typename T> template <typename VST>
void BinNode<T>::travLevel(VST & visit){//层次遍历
    Queue<BinNodePosi<T>> Q;//辅助队列
    Q.enqueue(this);//根节点入队
    while (!Q.empty()) {//在队列再次变空之前，反复迭代
        BinNodePosi<T> x = Q.dequeue(); visit(x->data);//取出首节点并访问之
        if (HasLChild(*x)) Q.enqueue(x->lc);//左孩子入队
        if (HasRChild(*x)) Q.enqueue(x->rc);//右孩子入队
    }
}