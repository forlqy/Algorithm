#include "BinNode.h"
//ͨ��zig��ת����BST����x��������Ҳ�ͨ·
template <typename T>
void stretchByZig(BinNodePosi<T>& x){
    BinNodePosi<T> v = x;
    while(x->lc) x = x->lc;
    for( ; v; v = v->rc){
        while(v->lc)
          v = v->zig();
    }
}