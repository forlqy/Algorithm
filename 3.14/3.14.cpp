const_iterator& operator+ (int k) {
	const_iterator advanced = *this;
	for (int i = 0; i < k; i++)
		advanced.current = advanced.current->next;
	return advanced;
}