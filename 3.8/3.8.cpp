iterator insert(iterator pos, const Object& x) {
	Object* iter = &objects[0];
	Object* oldArray = objects;
	theSize++;
	int i;
	if (theCapacity < theSize)
		theCapacity = theSize;
	objects = new Object[theCapacity];
	while (iter != pos) {
		objects[i] = oldArray[i];
		iter += sizeOf(Object);
		pos += sizeOf(Object);
		i++;
	}
	objects[pos] = x;
	for (int k = pos + 1; k < theSize; k++)
		objects[k] = oldArray[k];

	delete[] oldArray;
	return &objects[pos];
}