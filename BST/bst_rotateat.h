/*BST节点旋转变换统一算法(3+4)，返回调整之后局部子树根节点的位置
注意：尽管子树根会正确的指向上层节点(若存在)，但反向的联接须由上层函数完成
*/
#include "bst.h"
template<typename T> BinNodePosi<T> BST<T>::rotateAt(BinNodePosi<T> v){//v为非空孙辈节点
    BinNodePosi<T> p = v->parent; BinNodePosi<T> g = p->parent;//视v,p,g相对位置分为四种情况
    if(IsLChild(*p))/*zig*/
        if(IsLChild(*v)){/*zig-zig*/
            p->parent = g->parent;//向上联接
            return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
        }else{/*zig-zag*/
            v->parent = g->parent;
            return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
        }
    else/*zag*/
        if(IsRChild(*v)){/*zag-zag*/
            p->parent = g->parent;
            return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
        }else{/*zag-zig*/
            v->parent = g->parent;
            return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
        }
}