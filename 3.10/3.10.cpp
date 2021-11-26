//这些更改是const_iterator类、迭代器类以及对使用或返回迭代器的所有矢量函数的更改。这些类和函数如下三个代码示例所示。
//根据文本中定义的矢量，只有更改包括begin()和end()。
//(a)
using namespace std;
class const_iterator {
public:
	//const_iterator() : current(NULL)
	// {}       强制使用安全构造函数
	const Object& operator* ()const {
		return retrieve();
	}
	const_iterator& operator++ () {
		current++;
		return *this;
	}

	const_iterator operator++ (int) {
		const_iterator old = *this;
		++(*this);
		return old;
	}

	bool operator== (const const_iterator& rhs)const {
		return current == rhs.current;
	}
	bool operator!= (const const_iterator& rhs)const {
		return !(*this == rhs);
	}

protected:
	Object* current;
	const Vector<Object>* theVect;

	Object& retrieve()const {
		assertIsValid();
		return *current;
	}

	const_iterator(const Vector<Object>& vect, Object* p) : theVect(&vect), current(p) {}

	void assertIsValid()const {
		if (theVect == NULL || current == NULL)
			throw IteratorOutOfBoundsException();
	}

	friend class Vector<Object>;
};


//(b)
class iterator : public const_iterator {
public:
	Object& operator* (){return retrieve() }
	const Object& operator* ()const { return const_iterator::operator* (); }

	iterator& operator++ () {
		cout << "old" << *current << " ";
		current++;
		cout << "new" << *current << " ";
		return *this;
	}

	iterator operator++ (int) {
		iterator old = *this;
		++(*this);
		return old;
	}
protected:
	iterator(const Vector<Object>& vect, Object* p) : const_iterator(vect, p){}
	friend class Vector<Object>;
};

//c
iterator begin() {
	return iterator(*this, &objects[0]);
}
const_iterator begin()const {
	return const_iterator(*this, &objects[0]);
}
iterator end() {
	return iterator(*this, &objects[size()]);
}
const_iterator end()const {
	return const_iterator(*this, &objects[size()]);
}
