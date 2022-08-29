#include "BinNode.h"
//通过zig旋转，将BST子树x拉伸成最右侧通路
template <typename T>
void stretchByZig(BinNodePosi<T>& x){
    BinNodePosi<T> v = x;
    while(x->lc) x = x->lc;
    for( ; v; v = v->rc){
        while(v->lc)
          v = v->zig();
    }
}