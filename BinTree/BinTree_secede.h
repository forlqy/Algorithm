#include "BinTree.h"
#include <type_traits>
template<typename T>//���������������㷨:������x�ӵ�ǰ��ժ���������װΪһ�Ŷ�����������
BinTree<T>* BinTree<T>::secede(BinNodePosi<T> x){//assert:�Ϸ�
    FromParentTo(*x) = nullptr;//�ж����Ը��ڵ��ָ��
    updateHeightAbove(x->parent);//����ԭ�����������ȵĸ߶�
    BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = nullptr;//������xΪ��
    S->_size = x->size(); _size -= S->_size; return S;//���¹�ģ�����ط����������
}