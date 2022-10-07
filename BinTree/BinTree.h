#include "BinNode.h"
template<typename T> class BinTree{//������ģ����
protected:
    int _size; BinNodePosi<T> _root;//��ģ�����ڵ�
    virtual int updateHeight(BinNodePosi<T> x);//���½ڵ�x�߶Ȳ�����
    void updateHeightAbove(BinNodePosi<T> x);//����x�������ȵĸ߶�
public:
    BinTree(): _size(0), _root(nullptr){}//���캯��
    ~BinTree(){if (0 < _size) remove(_root);}//��������
    int size() const{return _size;}//��ģ
    bool empty() const{return !_root;}//�п�
    BinNodePosi<T> root() const{return _root;}//����
    BinNodePosi<T> insert(T const &);//������ڵ�
    BinNodePosi<T> insert(T const &, BinNodePosi<T>);//��������
    BinNodePosi<T> insert(BinNodePosi<T>, T const &);//�Һ���
    BinNodePosi<T> attach(BinTree<T>* &, BinNodePosi<T>);//����������
    BinNodePosi<T> attach(BinNodePosi<T>, BinTree<T>* &);//����������
    int remove(BinNodePosi<T>);//����ɾ��
    BinTree<T>* secede(BinNodePosi<T>);//��������
    template<typename VST>//������
    void travLevel(VST& visit){if (_root) _root->travLevel(visit);}//��α���
    template<typename VST>
    void travPre(VST& visit){if (_root) _root->travPre(visit);}//ǰ��
    template<typename VST>
    void travIn(VST& visit){if (_root) _root->travIn(visit);}//����
    template<typename VST>
    void travPost(VST& visit){if (_root) _root->travPost(visit);}//����
    bool operator< (BinTree<T> const& t)//�Ƚ���
    {return _root && t._root && (_root < t._root);}
    bool operator> (BinTree<T> const& t)
    {return _root && t._root && (_root > t._root);}
    bool operator== (BinTree<T> const& t)//�е���
    {return _root && t._root && (_root == t._root);}
    bool operator!= (BinTree<T> const& t)
    {return _root && t._root && (_root != t._root);}
};