//basic 
    //BinNode״̬�����ʵ��ж�
#define IsRoot(x) (!(x).parent)
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))//����ӵ��һ������
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))//�Ƿ�ΪҶ�ڵ�
    //��BinNode�����ض���ϵ�Ľڵ㼰ָ��
#define sibling(p) (IsLChild(*(p))) ? (p)->parent->rc : (p)->parent->lc/*�ֵ�*/
#define uncle(x) (slbling((x)->parent))/*����*/
#define FromParentTo(x) /*���Ը��׵�����*/\
    (IsRoot(x) ? _root : (IsLChildx ? (x).parent->lc : (x).parent->rc))

//Avl
#define Balanced(x) (stature((x).lc) == stature((x).rc))//����ƽ������
#define BalFac(x) (stature((x).lc) - stature((x).rc))//ƽ������
#define AvlBalanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2))//AVLƽ������

//redBlack
#define IsBlack(p) (!(p) || (RB_BLACK == (p)->color))//�ⲿ�ڵ�Ҳ�����ڽڵ�
#define IsRed(p) (!IsBlack(p))//�Ǻڼ���
#define BlackHeightUpdated(x)(/*RedBlack�߶ȸ�������*/ \
    (stature((x).lc) == stature((x).rc)) && \
    ((x).height == (IsRed(&x) ? stature((x).lc) : stature((x).lc) + 1)) \
)