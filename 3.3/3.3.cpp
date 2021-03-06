template <typename Iterator, typename Object>
Iterator find(Iterator start, Iterator end, const Object& x) {
	Iterator iter = start;
	while (iter != end && *iter != x)
		iter++;
	return iter;
}