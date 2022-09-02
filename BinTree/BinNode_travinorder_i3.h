#include "BinNode_travinorder.h"
template <typename T, typename VST>
void travIn_I3(BinNodePosi<T> x, VST& visit){//������3 ���踨��ջ
    bool backtrack = false;//ǰһ���Ƿ�մ�����������--ʡȥջ��O(1)�����ռ�
    while(true)
        if(!backtrack && HasLChild(*x))//�����������Ҳ��Ǹոջ��ݣ���
            x = x->lc;//�������������
        else{//����--����������ոջ��ݣ��൱������������
            visit(x->data);//���ʸýڵ�
            if(HasRChild(*x)){//�����������ǿգ���
                x = x->rc;//������������������
                backtrack = false;//�رջ��ݱ�־
            } else {//��������Ϊ�գ���
                if(!(x = x->succ())) break;//���ݣ����ִ�ĩ�ڵ�ʱ���˳����أ�
                backtrack = true;//�����û��ݱ�־
            }
        }
}