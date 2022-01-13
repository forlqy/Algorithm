//const_reverse_iterator类几乎与const_iterator相同，而reverse_iterator与iterator类几乎相同。将++重新定义为--，并将类型const_iterator的所有变量更改为const_reverse_iterator,
//并将iterator改为reverse_iterator,在rbegin()和rend()的列表中添加两个新成员

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