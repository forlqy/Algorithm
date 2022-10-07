#include "avl.h"
template<typename T> BinNodePosi<T> AVL<T>::insert(const T& e){//将关键码e插入AVL树
    BinNodePosi<T>& x = this->search(e); if(x) return x;//确认目标节点不存在
    BinNodePosi<T> xx = x = new BinNode<T>(e,this->_hot); this->_size++;//创建新节点x
//此时，x的父亲_hot若增高，则其祖父有可能失衡
    for(BinNodePosi<T> g = this->_hot; g; g = g->parent)//从x之父出发向上，逐层检查各代祖先g
        if(!AvlBalanced(*g)){//一旦g失衡(采用"3+4"算法)使之复衡，并将子树
            FromParentTo(*g) = this->rotateAt(tallerChild(tallerChild(g)));//重新接入原树
            break;//局部子树复衡后，高度必然复原；其祖先亦必如此，固调整结束
        }else //(g仍平衡)
            this->updateHeight(g);//只需更新其高度(即使g未失衡，高度亦可能增加)
    return xx;//返回新节点位置
}//无论e是否存在于原树，总有AVL::insert(e)->data == e