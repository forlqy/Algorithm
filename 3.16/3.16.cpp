//const_reverse_iterator�༸����const_iterator��ͬ����reverse_iterator��iterator�༸����ͬ����++���¶���Ϊ--����������const_iterator�����б�������Ϊconst_reverse_iterator,
//����iterator��Ϊreverse_iterator,��rbegin()��rend()���б�����������³�Ա

const_reverse_iterator rbegin()const {
	return const_reverse_iterator itr(tail);
}

const_reverse_iterator rend() const {
	const_reverse_iterator itr(head);
}

reverse_iterator rbegin() {
	return reverse_iterator itr(tail);
}

reverse_iterator rend() {
	reverse_iterator itr(head);
}