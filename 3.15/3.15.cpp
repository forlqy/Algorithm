void splice(iterator itr, List<Object>& lst) {
	itr.assertIsValid();
	if (itr.theList != this)
		throw IteratorMismatchException();

	Node* p = iter.current;
	theSize += lst.size();
	p->prev->next = lst.head->next;
	lst.head->next->prev = p->prev;
	lst.tail->prev->next = p;
	p->prev = lst->tail->prev;
	lst.init();
}