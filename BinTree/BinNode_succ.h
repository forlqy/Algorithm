#include "BinNode.h"
template <typename T>
BinNodePosi<T> BinNode<T>::succ(){//��λ�ڵ�v��ֱ�Ӻ��
    BinNodePosi<T> s = this;//��¼��̵���ʱ����
    if(rc){//�����Һ��ӣ���ֱ�Ӻ�̱�����������
        s =rc;//����������
        while(HasLChild(*s)) s = s->lc;//�������������С���Ľڵ�
    }else{//����ֱ�Ӻ��Ӧ����"����ǰ�ڵ���������������е��������"
        while(IsRChild(*s)) s = s->parent;//������������֧�����ϳ����Ϸ��ƶ�
        s = s->parent;//����ٳ����Ϸ��ƶ�һ�������ִ�ֱ�Ӻ�̣������ڣ�
    }
    return s;
}