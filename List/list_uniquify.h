template <typename T>
int List<T>::uniquify(){//�����޳��ظ�Ԫ�أ�Ч�ʸ���
    if (_size < 2) return 0;//ƽ���б���Ȼ���ظ�
    intoldSize = _size;//��¼ԭ��ģ
    ListNodePosi<T> p = first(); ListNodePosi<T> q;//pΪ��������㣬qΪ����
    while (trailer != (q = p->succ))//����������ڵĽڵ��(p, q)
      if (p->data != q->data) p = q;//�����죬��ת����һ����
      else remove(q);//������ͬ��ֱ��ɾ��'����',����������������ӵ����ɾ��
    return oldSize - _size;//��ɾ��Ԫ������
}