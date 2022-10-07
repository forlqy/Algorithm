#include "BinNode_travpostorder.h"
template <typename T>//����Sջ���ڵ�Ϊ���������У��ҵ�������ɼ�Ҷ�ڵ�
static void gotoLeftmostLeaf(Stack<BinNodePosi<T>> S){//�����ڵ�������ջ
    while(BinNodePosi<T> x = S.pop()){//�Զ����£��������ջ������ǰ�ڵ�
        if(HasLChild(*x)){//����������
            if(HasRChild(*x)) S.push(x->rc);//�����Һ��ӣ�������ջ
            S.push(x->lc);//�����������Ӻ���ջ
        } else{//�򲻵���
            S.push(x->rc);//����������
        }
        S.pop();//����֮ǰ������ջ���սڵ㣨ѭ��������
    }
}

template <typename T, typename VST>
void travPost_I(BinNodePosi<T> x, VST& visit){
    Stack<BinNodePosi<T>> S;//����ջ
    if(x) S.push(x);//ѹ����ڵ�
    while(!S.empty()){//ֱ��ջ�գ�xʼ��Ϊ��ǰ�ڵ�
        if(S.top() != x->parent)//��ջ����x֮����Ϊ�����֣�
          gotoLeftmostLeaf(S);//�������������ҵ�HLVFL���൱�ڵݹ�����
        x = S.pop(); visit(x->data);//����ǰһ�ڵ�֮��̣���ջ����������֮
    }
}