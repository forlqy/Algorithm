#include "BinNode.h"
template <typename T>
int BinNode<T>::size(){//ͳ�Ƶ�ǰ�ڵ���������������Ϊ����������ģ
    int s = 1;//������������
    if (lc) s += lc->size();//�ݹ������������ģ
    if (rc) s += rc->size();//�ݹ������������ģ
    return s;
}