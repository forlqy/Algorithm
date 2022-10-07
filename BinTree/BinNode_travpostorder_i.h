#include "BinNode_travpostorder.h"
template <typename T>//在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
static void gotoLeftmostLeaf(Stack<BinNodePosi<T>> S){//所遇节点依次入栈
    while(BinNodePosi<T> x = S.pop()){//自顶向下，反复检查栈顶，当前节点
        if(HasLChild(*x)){//尽可能向左
            if(HasRChild(*x)) S.push(x->rc);//若有右孩子，优先入栈
            S.push(x->lc);//左子树的左孩子后入栈
        } else{//万不得已
            S.push(x->rc);//移向右子树
        }
        S.pop();//返回之前，弹出栈顶空节点（循环条件）
    }
}

template <typename T, typename VST>
void travPost_I(BinNodePosi<T> x, VST& visit){
    Stack<BinNodePosi<T>> S;//辅助栈
    if(x) S.push(x);//压入根节点
    while(!S.empty()){//直到栈空，x始终为当前节点
        if(S.top() != x->parent)//若栈顶非x之父（为其右兄）
          gotoLeftmostLeaf(S);//在其右兄子树找到HLVFL，相当于递归深入
        x = S.pop(); visit(x->data);//弹出前一节点之后继（即栈顶），访问之
    }
}