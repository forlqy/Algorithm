#pragma once
using Rank = int;
template <typename T>
static Rank binSearch(T* A, const T& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}//出口时，A[lo = hi]为大于e的最小元素
	return --lo;//故lo - 1为不大于e的元素的最大秩
}