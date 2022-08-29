//basic 
    //BinNode状态与性质的判断
#define IsRoot(x) (!(x).parent)
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))//至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))//是否为叶节点
    //与BinNode具有特定关系的节点及指针
#define sibling(p) (IsLChild(*(p))) ? (p)->parent->rc : (p)->parent->lc/*兄弟*/
#define uncle(x) (slbling((x)->parent))/*叔叔*/
#define FromParentTo(x) /*来自父亲的引用*/\
    (IsRoot(x) ? _root : (IsLChildx ? (x).parent->lc : (x).parent->rc))

//Avl
#define Balanced(x) (stature((x).lc) == stature((x).rc))//理想平衡条件
#define BalFac(x) (stature((x).lc) - stature((x).rc))//平衡因子
#define AvlBalanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2))//AVL平衡条件

//redBlack
#define IsBlack(p) (!(p) || (RB_BLACK == (p)->color))//外部节点也视作黑节点
#define IsRed(p) (!IsBlack(p))//非黑即红
#define BlackHeightUpdated(x)(/*RedBlack高度更新条件*/ \
    (stature((x).lc) == stature((x).rc)) && \
    ((x).height == (IsRed(&x) ? stature((x).lc) : stature((x).lc) + 1)) \
)