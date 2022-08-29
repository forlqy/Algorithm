#if defined(DSA_REDBLACK)
#define stature(p)((p) ? (p)->height : 0)//������ڵ�ĺڸ߶ȣ�NULL����Ϊ�ⲿ�ڵ㣬��Ӧ��0��
#else
#define stature(p)((p) ? (p)->height : -1)//����BST�нڵ�ĸ߶ȣ�NULL��Ϊ��������Ӧ��-1��
#endif
typedef enum{RB_RED, RB_BLACK} RBColor;//�ڵ���ɫ
template <typename T>struct BinNode;
template <typename T>using BinNodePosi = BinNode<T>*;//�ڵ�λ��
template <typename T>struct BinNode{//�������ڵ�ģ����
//��Ա��ͳһ���ţ��ɽ�һ����װ��
    T data;//����
    BinNodePosi<T> parent, lc, rc;//���ڵ㼰���Һ���
    int height;//�߶ȣ�ͨ�ã�
    int npl;//Null Path Length(��ʽ�ѣ�Ҳ��ֱ����height����)
    RBColor color;//��ɫ���������
//���캯��
    BinNode() : parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1), color(RB_RED){}//������ʼ���б�Ч�ʸߣ��ɲ�������nullptr����NULL��
    BinNode(T e, BinNodePosi<T> p = nullptr, BinNodePosi<T> lc = nullptr, BinNodePosi<T> rc = nullptr, int h = 0, int l = 1, RBColor c = RB_RED): 
        data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c){}//�вι��캯��
//�����ӿ�
    int size();//ͳ�Ƶ�ǰ�ڵ�ĺ��������������Ϊ����������ģ
    BinNodePosi<T> insertAsLC(T const &);//��Ϊ��ǰ�ڵ����Ӳ���
    BinNodePosi<T> insertAsRC(T const &);//��Ϊ��ǰ�ڵ��Һ��Ӳ���
    BinNodePosi<T> succ();//ȡ��ǰ�ڵ�ֱ�Ӻ��
    BinNodePosi<T> zig();//˳ʱ����ת
    BinNodePosi<T> zag();//��ʱ����ת
    template <typename VST> void travLevel(VST&);//������α���
    template <typename VST> void travPre(VST&);//�������
    template <typename VST> void travIn(VST&);//�������
    template <typename VST> void travPost(VST&);//�������
//�Ƚ������е��������Դ���ֵ���������أ�
    bool operator< (BinNode const& bn){return data < bn.data;}//С��
    bool operator== (BinNode const& bn){return data == bn.data;}//����
    bool operator> (BinNode const& bn){return data > bn.data;}//����
    bool operator!= (BinNode const& bn){return data != bn.data;}//������
};