#pragma once
using Rank = int;
template <typename T>
Rank InterpolationSearch(T* D, int dataLength, const T& targetValue) {
	Rank left = 0;
	Rank right = dataLength - 1;
	Rank mid;
	// ��ֹ����
	while (left < right)
	{
		// �м�λ�ü���
		mid = left + int((targetValue - D[left]) / (D[right] - D[left]) * (right - left));
		if (*(D + mid) == targetValue) {
			return mid;
		}
		// Ŀ��ֵ���м�ֵ�ұߣ�������λ��
		else if (*(D + mid) < targetValue) {
			left = mid + 1;
		}
		// Ŀ��ֵ���м�ֵ��ߣ�������λ��
		else
		{
			right = mid - 1;
		}
	}
	// ֻʣ���һ��Ԫ��ʱ
	if (left == right) {
		if (targetValue == D[left]) {
			return left;
		}
	};
	// ��������������-1
	return -1;
}