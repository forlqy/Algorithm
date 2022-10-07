#include "BinNode_travpreorder.h"
template<typename T,typename VST>//�ӵ�ǰ�ڵ㣬�����֧�������룬ֱ�������֧�Ľڵ㣻��;�ڵ�����������
static void visitAlongVine(BinNodePosi<T> x, VST& visit, Stack<BinNodePosi<T>> S){
    while(x){
        visit(x->data);
        if(x->rc){//�����ж�
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