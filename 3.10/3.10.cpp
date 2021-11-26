//��Щ������const_iterator�ࡢ���������Լ���ʹ�û򷵻ص�����������ʸ�������ĸ��ġ���Щ��ͺ���������������ʾ����ʾ��
//�����ı��ж����ʸ����ֻ�и��İ���begin()��end()��
//(a)
using namespace std;
class const_iterator {
public:
	//const_iterator() : current(NULL)
	// {}       ǿ��ʹ�ð�ȫ���캯��
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
