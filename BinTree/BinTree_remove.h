#include "BinTree.h"
template<typename T>//ɾ����������λ��x���Ľڵ�����������ر�ɾ���ڵ����ֵ
int BinTree<T>::remove(BinNodePosi<T> x){//assert:xΪ�������Ϸ�λ��
    FromParentTo(*x) = nullptr;//�ж����Ը��ڵ��ָ��
    updateHeightAbove(x->parent);//�������ȸ߶�
    int n = removeAt(x); _size -= n; return n;//ɾ������x�����¹�ģ������ɾ���ڵ�����
}

template<typename T>
static int removeAt(BinNodePosi<T> x){
    if(!x) return 0;//�ݹ��������
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);//�ݹ��ͷ���,������
    release(x->data); release(x); return n;//�ͷű�ժ���ڵ㣬������ɾ���ڵ�������release�ͷŸ��ӽṹ(delete)
}