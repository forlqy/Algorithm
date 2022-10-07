#include "btnode.h"

template<typename T> class BTree{//B-树模版类
protected:
    int _size;//存放关键码总数
    int _m;//B-树阶次，至少为3------创建时指定，一般不能修改
    BTNodePosi<T> _root;//根节点
    BTNodePosi<T> _hot;//BTree::search()最后访问的非空(除非树空)节点
    void solveOverflow(BTNodePosi<T>);//因插入而上溢之后的分裂处理
    void solveUnderflow(BTNodePosi<T>);//因删除而下溢之后的合并处理
public:
    BTree(int m = 3) : _m(m), _size(0)//构造函数：默认为最低3阶
    {_root = new BTNode<T>();}
    ~BTree(){if(_root) release(_root);}//析构函数：释放所有节点
    int const order(){return _m;}//阶次
    int const size(){return _size;}//规模
    BTNodePosi<T>& root(){return _root;}//根节点
    bool empty() const{return !_root;}//判空(加const可以被const修饰对象使用，同时无法修改数据成员的值)
    BTNodePosi<T> search(const T& e);//查找
    bool insert(const T& e);//插入
    bool remove(const T& e);//删除
};//BTree