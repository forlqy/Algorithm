typedef unsigned int U;

template <typename T>//���б���ʼ��λ��p,���Ϊn����������������
void List<T>::radixSort(ListNodePosi<T> p, int n){//valid(p) && rank(p) + n <= size
    ListNodePosi<T> head = p->pred; ListNodePosi<T> tail = p;
    for (int i = 0; i < n; i++) tail->succ;//����������(head, tail)
    for (U radixBit = 0x1; radixBit && (p = head); radixBit <<=1)//���·�����
      for (int i = 0; i < n; i++)//���ݵ�ǰ����λ�������нڵ�
        radixBit & U(p->succ->data) ? //�ּ�Ϊ��׺(1) ��ǰ׺(0)
          insert(remove(p->succ), tail) : p = p->succ;
}