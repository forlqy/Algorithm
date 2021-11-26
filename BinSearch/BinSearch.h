#pragma once
using Rank = int;
template <typename T>
static Rank binSearch(T* A, const T& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}//����ʱ��A[lo = hi]Ϊ����e����СԪ��
	return --lo;//��lo - 1Ϊ������e��Ԫ�ص������
}