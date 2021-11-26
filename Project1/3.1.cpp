#include <list>
#include <iostream>
#include <string>
using namespace std;

template <typename Object>
void printLots(list<Object> L, list<int> P) {
	typename list<int>::const_iterator pIter;
	typename list<Object>::const_iterator lIter;
	int start = 0;
	lIter = L.begin();
	for (pIter = P.begin(); pIter != P.end() && lIter != L.end(); pIter++) {
		while (start < *pIter && lIter != L.end()) {
			start++;
			lIter++;
		}
		if (lIter != L.end())
			cout << *lIter << endl;
	}
}

int main() {
	list<char> l1;
	list<int> l2;
	string myint1;
	cin >> myint1;
	for (int i = 0; unsigned (i) < myint1.length(); i++) {
		l1.push_back(myint1[i]);
	}
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(4);
    
	printLots(l1, l2);
}

//运行时间取决于P链表长度