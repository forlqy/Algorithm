#include "BinNode_travpreorder.h"
template<typename T,typename VST>//从当前节点，沿左分支不断深入，直至无左分支的节点；沿途节点遇到即访问
static void visitAlongVine(BinNodePosi<T> x, VST& visit, Stack<BinNodePosi<T>> S){
    while(x){
        visit(x->data);
        if(x->rc){//增加判断
        S.push(x->rc);
        }
        x = x->lc;
    }
}

template<typename T, typename VST>
void travPre_I(BinNodePosi<T> x, VST &visit){
    Stack<BinNodePosi<T>> S;
    while (true) {
        visitAlongVine(x, visit, S);
        if(S.empty()) break;
        x = S.pop();
    }
}