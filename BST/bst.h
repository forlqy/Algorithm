#include "../BinTree/BinTree.h"

template<typename T> class BST : public BinTree<T>{
protected:
    BinNodePosi<T> _hot;//"����"�ڵ�ĸ���
    BinNodePosi<T> connect34(//����"3+4"�ṹ�����������ڵ㼰�Ŀ�����(�����Ĵ��������6������Ĳ�������ջ֡��)
        BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
        BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>);
    BinNodePosi<T> rotateAt(BinNodePosi<T> x);//��x���丸�ף��游��ͳһ��ת����
public://virtual���Σ�ǿ��Ҫ������������(BST����)�������������д
    virtual BinNodePosi<T>& search(const T& e);//����
    virtual BinNodePosi<T> insert(const T& e);//����
    virtual bool remove(const T& e);//ɾ��
};