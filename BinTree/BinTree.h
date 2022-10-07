#include "BinNode.h"
template<typename T> class BinTree{//二叉树模版类
protected:
    int _size; BinNodePosi<T> _root;//规模，根节点
    virtual int updateHeight(BinNodePosi<T> x);//更新节点x高度并返回
    void updateHeightAbove(BinNodePosi<T> x);//更新x及其祖先的高度
public:
    BinTree(): _size(0), _root(nullptr){}//构造函数
    ~BinTree(){if (0 < _size) remove(_root);}//析构函数
    int size() const{return _size;}//规模
    bool empty() const{return !_root;}//判空
    BinNodePosi<T> root() const{return _root;}//树根
    BinNodePosi<T> insert(T const &);//插入根节点
    BinNodePosi<T> insert(T const &, BinNodePosi<T>);//插入左孩子
    BinNodePosi<T> insert(BinNodePosi<T>, T const &);//右孩子
    BinNodePosi<T> attach(BinTree<T>* &, BinNodePosi<T>);//接入左子树
    BinNodePosi<T> attach(BinNodePosi<T>, BinTree<T>* &);//接入右子树
    int remove(BinNodePosi<T>);//子树删除
    BinTree<T>* secede(BinNodePosi<T>);//子树分离
    template<typename VST>//操作器
    void travLevel(VST& visit){if (_root) _root->travLevel(visit);}//层次遍历
    template<typename VST>
    void travPre(VST& visit){if (_root) _root->travPre(visit);}//前序
    template<typename VST>
    void travIn(VST& visit){if (_root) _root->travIn(visit);}//中序
    template<typename VST>
    void travPost(VST& visit){if (_root) _root->travPost(visit);}//后序
    bool operator< (BinTree<T> const& t)//比较器
    {return _root && t._root && (_root < t._root);}
    bool operator> (BinTree<T> const& t)
    {return _root && t._root && (_root > t._root);}
    bool operator== (BinTree<T> const& t)//判等器
    {return _root && t._root && (_root == t._root);}
    bool operator!= (BinTree<T> const& t)
    {return _root && t._root && (_root != t._root);}
};