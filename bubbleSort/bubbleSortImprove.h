#pragma once
template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	while (lo < (hi = bubble(lo, hi)));
}
template <typename T>
Rank Vector<T>::bubble(Rank lo, Rank hi) {
	Rank last = lo;//���Ҳ������Գ�ʼ��Ϊ[lo - 1, lo]
	while (++lo < hi)//��������
		if (_elem[lo - 1] > _elem[lo]) {
			last = lo;//�������Ҳ������λ�ü�¼
			swap(_elem[lo - 1], _elem[lo]);
		}
	return last;//�������Ҳ������λ��
}//ǰһ�汾�е��߼��Ա�־sorted����Ϊ��last