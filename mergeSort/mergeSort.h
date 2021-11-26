#pragma once
#include "merge.h"
template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
	if (hi - lo < 2) return;//单元素区间自然有序
	Rank mi = (lo + hi) >> 1;//以中点为界
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);//归并
}