#pragma once
template <typename T>//�б��ڲ������������б�����λ��p���n��
void List<T>::copyNodes(ListNodePosi<T> p, int n) {//p�Ϸ�����������n-1�����̽ڵ�
	init();//����ͷ��β�ڱ��ڵ㲢��ʼ��
	while (n--) { insertAsLast(p->data); p = p->succ; }//������p��n��������Ϊĩ�ڵ����
}