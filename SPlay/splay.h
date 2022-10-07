#include "../BST/bst.h"
template<typename T> class Splay : public BST<T>{//由BST派生Splay树模版类
protected:
    BinNodePosi<T> splay(BinNodePosi<T> v);//将节点v伸展至根
public:
    BinNodePosi<T>& search(const T& e);//查找（重写）
    BinNodePosi<T> insert(const T& e);//插入（重写）
    bool remove(const T& e);//删除（重写）
};