#pragma once
template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	while (!bubble(lo, hi--));//������ɨ�轻����ֱ��ȫ��
}
template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true;//���������־
	while (++lo < hi)//�������ң���һ����������Ԫ��
		if (_elem[lo - 1] > _elem[lo]) {
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	return sorted;
}//��������[0, sqrt(n))ʱ������O��n��3/2�η���ʱ��--����O(n)Ӧ���Ѿ�����