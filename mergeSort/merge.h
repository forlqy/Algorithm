#pragma once
template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	T* A = _elem + lo;//�ϲ��������A[0, hi - lo) = _elem[lo, hi)
	int lb = mi - lo; T* B = new T[lb];//ǰ������B[0, lb) = _elem[lo, mi)
	for (Rank i = 0; i < lb; B[i] = A[i++]);//����ǰ������B
	int lc = hi - mi; T* C = _elem + mi;//Cû�б�Ҫ������ʱ�ռ䣬B�����ԭ���Ƿ�ֹԪ�ر�����
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {//B[j]�� C[k]��С��ת��A��ĩβ
		if ((j < lb) && (lc <= k || (B[j] <= C[k]))) A[i++] = B[j++];//C[k]���޻�С
		if ((k < lc) && (lb <= j || (C[k] < B[j]))) A[i++] = C[k++];//B[j]���޻����
	}//ʵ�ֽ��գ���Ч�ʲ����ִ���
	/*for (Rank i = 0, j = 0, k = 0; j < lb;) {//
		if (lc <= k || (B[j] <= C[k])) A[i++] = B[j++];//����ʵ�֣�����Ҫ����B�ľ�ʱC��Ҫ������A�ƶ�Ԫ�أ���ΪC��������A�ĺ�벿��
		if ((k < lc) && (C[k] < B[j])) A[i++] = C[k++];//*/
	delete[] B;//�ͷ���ʱ�ռ�B
}