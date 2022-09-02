#include "BinNode_travinorder.h"
template <typename T, typename VST>
void travIn_I3(BinNodePosi<T> x, VST& visit){//迭代版3 无需辅助栈
    bool backtrack = false;//前一步是否刚从左子树回溯--省去栈，O(1)辅助空间
    while(true)
        if(!backtrack && HasLChild(*x))//若有左子树且不是刚刚回溯，则
            x = x->lc;//深入遍历左子树
        else{//否则--无左子树或刚刚回溯（相当于无左子树）
            visit(x->data);//访问该节点
            if(HasRChild(*x)){//若其右子树非空，则
                x = x->rc;//深入右子树继续遍历
                backtrack = false;//关闭回溯标志
            } else {//若右子树为空，则
                if(!(x = x->succ())) break;//回溯（含抵达末节点时的退出返回）
                backtrack = true;//并设置回溯标志
            }
        }
}