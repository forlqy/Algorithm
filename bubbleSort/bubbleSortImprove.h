#pragma once
template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	while (lo < (hi = bubble(lo, hi)));
}
template <typename T>
Rank Vector<T>::bubble(Rank lo, Rank hi) {
	Rank last = lo;//最右侧的逆序对初始化为[lo - 1, lo]
	while (++lo < hi)//自左向右
		if (_elem[lo - 1] > _elem[lo]) {
			last = lo;//更新最右侧逆序对位置记录
			swap(_elem[lo - 1], _elem[lo]);
		}
	return last;//返回最右侧逆序对位置
}//前一版本中的逻辑性标志sorted，改为秩last