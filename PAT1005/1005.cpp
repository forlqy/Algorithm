#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> intVector;
	
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		intVector.push_back(number);
	}
	vector<int> linshi;
	vector<int>::iterator it1 = intVector.begin();
	for (; it1 != intVector.end();it1++) {
		while (*it1 != 1) {
			if (*it1 % 2 == 0) {
				*it1 /= 2;
				linshi.push_back(*it1);
			}

			else
			{
				*it1 = ((3 * (*it1) + 1) / 2);
				linshi.push_back(*it1);
			}
		}
			
		}
	vector<int>::iterator it2 = intVector.begin() + 1;
		for (; it2 != intVector.end(); it2++) {
			for (int i = 0; i < linshi.size(); i++)  {
				if (linshi[i] == *it2)intVector.erase(it2);//Òì³£
			}
		}
	
	sort(intVector.rbegin(), intVector.rend());
	for (vector<int>::iterator it3 = intVector.begin(); it3 != intVector.end(); it3++) {
		cout << *it3 << " ";
	}
}