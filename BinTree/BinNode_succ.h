#include "BinNode.h"
template <typename T>
BinNodePosi<T> BinNode<T>::succ(){//定位节点v的直接后继
    BinNodePosi<T> s = this;//记录后继的临时变量
    if(rc){//若有右孩子，则直接后继必在右子树中
        s =rc;//进入右子树
        while(HasLChild(*s)) s = s->lc;//右子树中最靠左（最小）的节点
    }else{//否则，直接后继应该是"将当前节点包含于其左子树中的最低祖先"
        while(IsRChild(*s)) s = s->parent;//逆向的沿右向分支，不断朝左上方移动
        s = s->parent;//最后再朝右上方移动一步，即抵达直接后继（若存在）
    }
    return s;
}