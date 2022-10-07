#pragma once
#include <iostream>
#include <assert.h>
using Rank = int; //��
#define DEFAULT_CAPACITY  3 //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п�����Ϊ������

template <typename T> class Vector { //����ģ����
protected:
   Rank _size; int _capacity;  T* _elem; //��ģ��������������
   void copyFrom ( T const* A, Rank lo, Rank hi ); //������������A[lo, hi)
   void expand(); //�ռ䲻��ʱ����
   void shrink(); //װ�����ӹ�Сʱѹ��
   bool bubble ( Rank lo, Rank hi ); //ɨ�轻��
   void bubbleSort ( Rank lo, Rank hi ); //���������㷨
   Rank maxItem ( Rank lo, Rank hi ); //ѡȡ����Ԫ��
   void selectionSort ( Rank lo, Rank hi ); //ѡ�������㷨
   void merge ( Rank lo, Rank mi, Rank hi ); //�鲢�㷨
   void mergeSort ( Rank lo, Rank hi ); //�鲢�����㷨
   void heapSort ( Rank lo, Rank hi ); //���������Ժ�������ȫ�ѽ��⣩
   Rank partition ( Rank lo, Rank hi ); //���㹹���㷨
   void quickSort ( Rank lo, Rank hi ); //���������㷨
   void shellSort ( Rank lo, Rank hi ); //ϣ�������㷨
public:
// ���캯��
   Vector ( int c = DEFAULT_CAPACITY, int s = 0, T v = 0 ) //����Ϊc����ģΪs������Ԫ�س�ʼΪv
   { _elem = new T[_capacity = c]; for ( _size = 0; _size < s; _elem[_size++] = v ); } //s<=c
   Vector ( T const* A, Rank n ) { copyFrom ( A, 0, n ); } //�������帴��
   Vector ( T const* A, Rank lo, Rank hi ) { copyFrom ( A, lo, hi ); } //����
   Vector ( Vector<T> const& V ) { copyFrom ( V._elem, 0, V._size ); } //�������帴��
   Vector ( Vector<T> const& V, Rank lo, Rank hi ) { copyFrom ( V._elem, lo, hi ); } //����
// ��������
   ~Vector() { delete [] _elem; } //�ͷ��ڲ��ռ�
// ֻ�����ʽӿ�
   Rank size() const { return _size; } //��ģ
   bool empty() const { return !_size; } //�п�
   Rank find ( T const& e ) const { return find ( e, 0, _size ); } //����������������
   Rank find ( T const& e, Rank lo, Rank hi ) const; //����������������
   Rank search ( T const& e ) const //����������������
   { return ( 0 >= _size ) ? -1 : search ( e, 0, _size ); }
   Rank search ( T const& e, Rank lo, Rank hi ) const; //����������������
// ��д���ʽӿ�
   T& operator[] ( Rank r ); //�����±�������������������������ʽ���ø�Ԫ��
   const T& operator[] ( Rank r ) const; //����������ֵ�����ذ汾
   Vector<T> & operator= ( Vector<T> const& ); //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
   T remove ( Rank r ); //ɾ����Ϊr��Ԫ��
   int remove ( Rank lo, Rank hi ); //ɾ����������[lo, hi)֮�ڵ�Ԫ��
   Rank insert ( Rank r, T const& e ); //����Ԫ��
   Rank insert ( T const& e ) { return insert ( _size, e ); } //Ĭ����ΪĩԪ�ز���
   void sort ( Rank lo, Rank hi ); //��[lo, hi)����
   void sort() { sort ( 0, _size ); } //��������
   void unsort ( Rank lo, Rank hi ); //��[lo, hi)����
   void unsort() { unsort ( 0, _size ); } //��������
   int deduplicate(); //����ȥ��
   int uniquify(); //����ȥ��
// ����
   void traverse ( void (* ) ( T& ) ); //������ʹ�ú���ָ�룬ֻ�����ֲ����޸ģ�
   template <typename VST> void traverse ( VST& ); //������ʹ�ú������󣬿�ȫ�����޸ģ�
}; //Vector


template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T> const& V) {//���
	if (_elem) delete[] _elem;//�ͷ�ԭ������
	copyFrom(V._elem, 0, V._size);//���忽��
	return *this;//���ص�ǰ���������ã��Ա���ʽ��ֵ
}

template <typename T>
T& Vector<T>::operator[] (Rank r) { //�����±�������
	assert(r >= 0 && r < _size);
	return _elem[r];
}

template <typename T>
const T& Vector<T>::operator[] (Rank r)const {
	assert(r >= 0 && r < _size);
	return _elem[r];
}

template <typename T>
void Vector<T>::copyFrom(const T* A, Rank lo, Rank hi) {//����������[lo, hi)Ϊ��������
	_elem = new T[_capacity = 2 * (hi - lo)];//�����ռ�
	for (_size = 0; lo < hi; _size++, lo++) {
		_elem[_size] = A[lo];//const���Σ���֤ԭ���鲻�ᱻ�۸�
	}//O(hi - lo)
}

template <typename T>
T Vector<T>::remove(Rank r) { //ɾ����������Ϊr��Ԫ�أ�0 <= r < size
	T e = _elem[r]; //���ݱ�ɾ��Ԫ��
	remove(r, r + 1); //��������ɾ���㷨����Ч�ڶ�����[r, r + 1)��ɾ��
	return e; //���ر�ɾ��Ԫ��
}

template <typename T> int Vector<T>::remove(Rank lo, Rank hi) { //ɾ������[lo, hi)
	if (lo == hi) return 0; //����Ч�ʿ��ǣ����������˻�����������remove(0, 0)
	while (hi < _size) //����[hi, _size)
		_elem[lo++] = _elem[hi++]; //˳��ǰ��hi - lo����Ԫ
	_size = lo; //���¹�ģ��ֱ�Ӷ���β��[lo, _size = hi)����
	shrink(); //���б�Ҫ��������
	return hi - lo; //���ر�ɾ��Ԫ�ص���Ŀ
}