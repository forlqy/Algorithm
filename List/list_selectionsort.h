template <typename T>//���б�����ʼ��λ��P�����ΪN��������ѡ������
void List<T>::selectionSort(ListNodePosi<T> p, int n){//valid(p) && rank(p) + n <= size
    ListNodePosi<T> head = p->pred, tail = p;
    for (int i = 0; i < n; i++) tail = tail->succ;//����������Ϊ(head,tail)
    while (1 < n){//�����ٻ�ʣ�����ڵ�֮ǰ���ڴ�����������
        ListNodePosi<T> max = selectMax(head->succ, n);//�ҳ�����ߣ�����ʱ�������ȣ�
        insert(remove(max), tail);//�����ƶ�����������ĩβ(��Ϊ�����������Ԫ��)
        tail = tail->pred; n--;
    }
}