#pragma once
#include "merge.h"
template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
	if (hi - lo < 2) return;//��Ԫ��������Ȼ����
	Rank mi = (lo + hi) >> 1;//���е�Ϊ��
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);//�鲢
}