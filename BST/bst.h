#include "../BinTree/BinTree.h"

template<typename T> class BST : public BinTree<T>{
protected:
    BinNodePosi<T> _hot;//"命中"节点的父亲
    BinNodePosi<T> connect34(//按照"3+4"结构，联接三个节点及四颗子树(参数寄存器最多有6个，多的参数放入栈帧中)
        BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
        BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>);
    BinNodePosi<T> rotateAt(BinNodePosi<T> x);//对x及其父亲，祖父做统一旋转调整
public://virtual修饰，强制要求所有派生类(BST变种)根据自身规则重写
    virtual BinNodePosi<T>& search(const T& e);//查找
    virtual BinNodePosi<T> insert(const T& e);//插入
    virtual bool remove(const T& e);//删除
};