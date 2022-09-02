#include "BinNode_travinorder.h"
template<typename T, typename VST>
void travIn_I2(BinNodePosi<T> x, VST& visit){//������ 2
    Stack<BinNodePosi<T>> S;//����ջ
    while(true){
        if(x){
            S.push(x);//���ڵ��ջ
            x = x->lc;//�������������
        } else if(!S.empty()){
            x = S.pop();//��δ���ʵ�������Ƚڵ���ջ
            visit(x->data);//���ʸ����Ƚڵ�
            x = x->rc;//�������ȵ�������
        } else
            break;//�������
    }
}