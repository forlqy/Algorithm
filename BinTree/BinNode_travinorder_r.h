#include "BinNode_travinorder.h"
template <typename T, typename VST>
void travIn_R(BinNodePosi<T> x, VST& visit){//����������ݹ�棩
    if(!x) return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}