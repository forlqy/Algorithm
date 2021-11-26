#include <iostream>
#include <list>

//O(N min(M,  N))
//if (M = 1),linear,O(N)
//Ô¼Éª·ò»·
using namespace std;

int main() {
	int i, j, n, m, mPrime, numLeft;
	list<int> L;
	list<int>::iterator iter;
	//
	cout << "enter N (# of people) & M (# of passes before elimination): ";
	cin >> n >> m;
	numLeft = n;
	mPrime = m % n;
	for (i = 1; i <= n; i++) {
		L.push_back(i);
	}
	iter = L.begin();
	//
	for (i = 0; i < n; i++) {
		mPrime = mPrime % numLeft;
		if (mPrime <= numLeft / 2)//pass forward
			for (j = 0; j < mPrime; j++) {
				iter++;
				if (iter == L.end())
					iter = L.begin();
			}
		else                      //pass backward
			for (j = 0; j < mPrime; j++) {
				if (iter == L.begin())
					iter = --L.end();
				else
					iter--;
			}
		cout << *iter << " ";
		iter = L.erase(iter);
		if (iter == L.end())
			iter = L.begin();
	}
	cout << endl;
	return 0;
}