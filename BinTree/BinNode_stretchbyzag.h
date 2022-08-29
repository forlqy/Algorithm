#include "BinNode.h"
//通过zag旋转，将BST子树X拉伸成最左侧通路
template <typename T>
void stretchByZag(BinNodePosi<T>& x){
    BinNodePosi<T> p = x; while(p->rc) p = p->rc;//最大节点，必是子树最终根
    while(x->lc) x = x->lc;//转至初始最左侧通路的末端
    for( ; x != p; x = x->parent){//若x右子树已空，则上升一层
        while(x->rc)//否则，反复
          x->zag();//以x为轴做zag旋转
    }
}