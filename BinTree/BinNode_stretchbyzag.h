#include "BinNode.h"
//ͨ��zag��ת����BST����X����������ͨ·
template <typename T>
void stretchByZag(BinNodePosi<T>& x){
    BinNodePosi<T> p = x; while(p->rc) p = p->rc;//���ڵ㣬�����������ո�
    while(x->lc) x = x->lc;//ת����ʼ�����ͨ·��ĩ��
    for( ; x != p; x = x->parent){//��x�������ѿգ�������һ��
        while(x->rc)//���򣬷���
          x->zag();//��xΪ����zag��ת
    }
}