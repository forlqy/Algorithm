template <typename T>
void List<T>::traverse(void(*visit)(T&)��){//��������ָ����Ʊ���
    for (ListNodePosi<T> p = header->succ; p != trailer; p = p->succ) visit(p->data);
}

template <typename T> template <typename VST>//Ԫ�����ͣ�������
void List<T>::traverse(VST& visit){//��������������Ʊ���
    for (ListNodePosi<T> p = header->succ; p != trailer; p = p->succ) visit(p->data);
}
