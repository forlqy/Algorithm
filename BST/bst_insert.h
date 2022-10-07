#include  "bst.h"
template<typename T> BinNodePosi<T> BST<T>::insert(const T& e){//将关键码e插入BST树中
    BinNodePosi<T>& x = search(e); if(x) return x;//确认目标不存在(留意对_hot的设置)
    x = new BinNode<T>(e, _hot);//创建新节点x:以e为关键码，_hot为父
    this->_size++;//不指定模版类或使用this指针会报错，why? 更新规模
    this->updateHeightAbove(x);//更新x及其历代祖先的高度
    return x;//新插入的节点，必为叶节点
}//无论是否存在于原树，返回时x->data == e