#if defined(DSA_REDBLACK)
#define stature(p)((p) ? (p)->height : 0)//红黑树节点的黑高度（NULL视作为外部节点，对应于0）
#else
#define stature(p)((p) ? (p)->height : -1)//其余BST中节点的高度（NULL视为空树，对应于-1）
#endif
typedef enum{RB_RED, RB_BLACK} RBColor;//节点颜色
template <typename T>struct BinNode;
template <typename T>using BinNodePosi = BinNode<T>*;//节点位置
template <typename T>struct BinNode{//二叉树节点模版类
//成员（统一开放，可进一步封装）
    T data;//数据
    BinNodePosi<T> parent, lc, rc;//父节点及左右孩子
    int height;//高度（通用）
    int npl;//Null Path Length(左式堆，也可直接用height代替)
    RBColor color;//颜色（红黑树）
//构造函数
    BinNode() : parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1), color(RB_RED){}//函数初始化列表，效率高；可不可以用nullptr代替NULL？
    BinNode(T e, BinNodePosi<T> p = nullptr, BinNodePosi<T> lc = nullptr, BinNodePosi<T> rc = nullptr, int h = 0, int l = 1, RBColor c = RB_RED): 
        data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c){}//有参构造函数
//操作接口
    int size();//统计当前节点的后代总数，即以其为根的子树规模
    BinNodePosi<T> insertAsLC(T const &);//作为当前节点左孩子插入
    BinNodePosi<T> insertAsRC(T const &);//作为当前节点右孩子插入
    BinNodePosi<T> succ();//取当前节点直接后继
    BinNodePosi<T> zig();//顺时针旋转
    BinNodePosi<T> zag();//逆时针旋转
    template <typename VST> void travLevel(VST&);//子树层次遍历
    template <typename VST> void travPre(VST&);//先序遍历
    template <typename VST> void travIn(VST&);//中序遍历
    template <typename VST> void travPost(VST&);//后序遍历
//比较器，判等器（类自带赋值操作符重载）
    bool operator< (BinNode const& bn){return data < bn.data;}//小于
    bool operator== (BinNode const& bn){return data == bn.data;}//等于
    bool operator> (BinNode const& bn){return data > bn.data;}//大于
    bool operator!= (BinNode const& bn){return data != bn.data;}//不等于
};