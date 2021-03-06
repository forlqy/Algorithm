#include <list>
using namespace std;

template <typename Object>
list<Object> listUnion(const list<Object>& L1, const list<Object>& L2) {
	list<Object> result;
	typename list<Object>::const_iterator iterL1 = L1.begin();
	typename list<Object>::const_iterator iterL2 = L2.begin();
	while (iterL1 != L1.end() && iterL2 != L2.end()) {
		if (*iterL1 == *iterL2) {
			result.push_back(*iterL1);
			iterL1++;
			iterL2++;
		}
		else if (*iterL1 < *iterL2) {
			result.push_back(*iterL1);
			iterL1++;
		}
		else {
			result.push_back(*iterL2);
			iterL2++;
		}
	}
	return result;
}