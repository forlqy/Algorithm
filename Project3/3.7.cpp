//vector Ë÷Òı±ß½ç¼ì²é

Object& operator[] (int index) {
	if (index >= 0 && index < size())
		return objects[index];
	else
		cout << "index out of bounds\n";
	return objects[0];
}

const Object& operator[] (int index) const{
	if (index >= 0 && index < size())
		return objects[index];
	else
		cout << "index out of bounds\n";
	return objects[0];
}