#include "BinNode_travinorder.h"
template <typename T>//�ӵ�ǰ�ڵ�����������֧�������룬ֱ��û�����֧�Ľڵ�
static void goAlongVine(BinNodePosi<T> x, Stack<BinNodePosi<T>>& S){
    while(x) {S.push(x); x = x->lc;}//��ǰ�ڵ���ջ���漴������֧���룬����ֱ��������
}

template <typename T, typename VST>//Ԫ�����ͣ�������
void travIn_I1(BinNodePosi<T> x, VST& visit){//������������� ����1��
    Stack<BinNodePosi<T>> S;//����ջ
    while(true){
        goAlongVine(x, S);//�ӵ�ǰ�ڵ������������ջ
        if(S.empty()) break;//ֱ�����нڵ㴦�����
        x = S.pop(); visit(x->data);//����ջ���ڵ㲢����֮
        x = x->rc;//ת��������
    }
}