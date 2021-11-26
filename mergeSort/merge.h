#pragma once
template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	T* A = _elem + lo;//合并后的向量A[0, hi - lo) = _elem[lo, hi)
	int lb = mi - lo; T* B = new T[lb];//前子向量B[0, lb) = _elem[lo, mi)
	for (Rank i = 0; i < lb; B[i] = A[i++]);//复制前子向量B
	int lc = hi - mi; T* C = _elem + mi;//C没有必要申请临时空间，B申请的原因是防止元素被覆盖
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {//B[j]和 C[k]中小者转至A的末尾
		if ((j < lb) && (lc <= k || (B[j] <= C[k]))) A[i++] = B[j++];//C[k]已无或不小
		if ((k < lc) && (lb <= j || (C[k] < B[j]))) A[i++] = C[k++];//B[j]已无或更大
	}//实现紧凑，但效率不如拆分处理
	/*for (Rank i = 0, j = 0, k = 0; j < lb;) {//
		if (lc <= k || (B[j] <= C[k])) A[i++] = B[j++];//精简实现，不需要考虑B耗尽时C还要继续往A移动元素，因为C本来就是A的后半部分
		if ((k < lc) && (C[k] < B[j])) A[i++] = C[k++];//*/
	delete[] B;//释放临时空间B
}