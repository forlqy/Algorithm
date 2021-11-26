#pragma once
using Rank = int;
template <typename T>
Rank InterpolationSearch(T* D, int dataLength, const T& targetValue) {
	Rank left = 0;
	Rank right = dataLength - 1;
	Rank mid;
	// 终止条件
	while (left < right)
	{
		// 中间位置计算
		mid = left + int((targetValue - D[left]) / (D[right] - D[left]) * (right - left));
		if (*(D + mid) == targetValue) {
			return mid;
		}
		// 目标值在中间值右边，更新左位置
		else if (*(D + mid) < targetValue) {
			left = mid + 1;
		}
		// 目标值在中间值左边，更新右位置
		else
		{
			right = mid - 1;
		}
	}
	// 只剩最后一个元素时
	if (left == right) {
		if (targetValue == D[left]) {
			return left;
		}
	};
	// 搜索不到，返回-1
	return -1;
}