typedef unsigned int U;

template <typename T>//对列表起始于位置p,宽度为n的区间做基数排序
void List<T>::radixSort(ListNodePosi<T> p, int n){//valid(p) && rank(p) + n <= size
    ListNodePosi<T> head = p->pred; ListNodePosi<T> tail = p;
    for (int i = 0; i < n; i++) tail->succ;//待排序区间(head, tail)
    for (U radixBit = 0x1; radixBit && (p = head); radixBit <<=1)//以下反复的
      for (int i = 0; i < n; i++)//根据当前基数位，将所有节点
        radixBit & U(p->succ->data) ? //分拣为后缀(1) 与前缀(0)
          insert(remove(p->succ), tail) : p = p->succ;
}