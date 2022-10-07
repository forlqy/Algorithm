#include "BinNode_travpreorder.h"
template<typename T, typename VST>
void travPre_R(BinNodePosi<T> x, VST& visit){
    if(!x) return;
    visit(x->data);
    travPre_R(x->lc, visit);
    travPre_R(x->rc, visit);
}