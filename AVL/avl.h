#include "../BST/bst.h"
#include "avl_macro.h"
template<typename T> class AVL : public BST<T>{//由BST派生AVL树模版类
public:
    BinNodePosi<T> insert(const T& e);//插入（重写）
    bool remove(const T& e);//删除（重写）
//BST::search()等其余接口直接沿用
};