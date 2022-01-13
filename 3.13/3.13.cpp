const_iterator& operator-- () {
	current = current->prev;
	return *this;
}

const_iterator operator-- (int) {
	const_iterator old = *this;
	--(*this);
	return old;
}