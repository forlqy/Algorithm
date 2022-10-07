#include "avl.h"
template<typename T> bool AVL<T>::remove(const T& e){//从Avl删除关键码e
    BinNodePosi<T>& x = this->search(e); if(!x) return false;//确认目标存在，留意_hot
    removeAt(x, this->_hot); this->_size--;//先按BST规则删除之(此后，原节点之父_hot及其祖先均可能失衡)
    for(BinNodePosi<T> g = this->_hot; g; g = g->parent){//从_hot出发向上，逐层检查各代祖先g
        if(!AvlBalanced(*g))//一旦g失衡，(3+4)使之复衡，并将该子树联至
            g = FromParentTo(*g) = this->rotateAt(tallerChild(tallerChild(g)));//原父亲
        this->updateHeight(g);//更新高度(override) 
    }//可能需O(logn)次调整--无论是否做过调整，全树高度均可能降低
    return true;//删除成功
}