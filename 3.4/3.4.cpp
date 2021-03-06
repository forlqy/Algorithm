//Assumes both input lists  are sorted
#include <list>
using namespace std;


template <typename Object>
list<Object> intersection(const list<Object>& L1, const list<Object>& L2) {
	list<Object> intersect;
	typename list<Object>::const_iterator iterL1 = L1.begin();//嵌套从属类型名称要使用typename 
	typename list<Object>::const_iterator iterL2 = L2.begin();
	while (iterL1 != L1.end() && iterL2 != L2.end()) {
		if (*iterL1 == *iterL2) {
			intersect.push_back(*iterL1);
			iterL1++;
			iterL2++;
		}
		else if (*iterL1 < *iterL2)
			iterL1++;
		else
			iterL2++;
	}
	return intersect;
}