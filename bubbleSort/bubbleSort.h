#pragma once
template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	while (!bubble(lo, hi--));//逐趟做扫描交换，直至全序
}
template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true;//整体有序标志
	while (++lo < hi)//自左向右，逐一检查各对相邻元素
		if (_elem[lo - 1] > _elem[lo]) {
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	return sorted;
}//乱序限于[0, sqrt(n))时，仍需O（n的3/2次方）时间--按理，O(n)应该已经足矣