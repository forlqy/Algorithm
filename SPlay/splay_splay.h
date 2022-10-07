#include "splay.h"
template<typename NodePosi> inline//在节点*p与*lc(可能nullptr)之间建立父(左)子关系
void attachAsLC(NodePosi lc, NodePosi p){p->lc = lc; if(lc)lc->parent = p;}

template<typename NodePosi> inline//在节点*p与*rc(可能nullptr)之间建立父(右)子关系
void attachAsRC(NodePosi p, NodePosi rc){p->rc = rc; if(rc)rc->parent = p;}

template<typename T> //Splay树伸展算法：从节点v出发逐层伸展
BinNodePosi<T> Splay<T>::splay(BinNodePosi<T> v){//v为因最近访问而需伸展的节点位置
    if(!v) return nullptr; BinNodePosi<T> p; BinNodePosi<T> g;//*v的父亲与祖父
    while((p = v->parent) && (g = p->parent)){//自下而上，反复对*v做双层伸展
        BinNodePosi<T> gg = g->parent;//每轮后*v都以原曾祖父(great-grand parent)为父
        if(IsLChild(*v))
          if(IsLChild(*p)){//zig-zig
            attachAsLC(p->rc, g); attachAsLC(v->rc, p);
            attachAsRC(p, g); attachAsRC(v, p);
          }else{//zig-zag
            attachAsLC(v->rc, p); attachAsRC(g, v->lc);
            attachAsLC(g, v); attachAsRC(v, p);
          }
        else if(IsRChild(*p)){//zag-zag
            attachAsRC(g, p->lc); attachAsRC(p, v->lc);
            attachAsLC(g, p); attachAsLC(p, v);
        }else{//zag-zig
            attachAsRC(p, v->lc); attachAsLC(v->rc, g);
            attachAsRC(v, g); attachAsLC(p, v);
        }
        if(!gg) v->parent = nullptr;//若*v原曾祖父*gg不存在,则*v现在应为树根
        else//否则，*gg此后应该以*v作为左或右孩子
         (g == gg->lc) ? attachAsLC(v, gg) : attachAsRC(gg, v);
        updateHeight(g); updateHeight(p); updateHeight(v);
    }//双层伸展结束时，必有g == nullptr,但p可能非空
    if((p = v->parent)){//若p果真非空，则额外再做一次单旋
        if(IsLChild(*v)){attachAsLC(v->rc, p); attachAsRC(v, p);}
        else            {attachAsRC(p, v->lc);attachAsLC(p, v);}
        updateHeight(p); updateHeight(v);
    }
    v->parent = nullptr; 
    return v;
}//调整后新树根应为被伸展的节点，故返回该节点以便上层函数更新树根