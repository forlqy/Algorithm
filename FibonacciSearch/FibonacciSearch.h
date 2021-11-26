#pragma once
#include "fib.h" //����Fib������
 // Fibonacci�����㷨���汾B��������������������[lo, hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
using Rank = int;
template <typename T> 
static Rank fibSearch(T * S, T const& e, Rank lo, Rank hi) {
     for (Fib fib(hi - lo); lo < hi; ) { //Fib�����Ʊ���
      while (hi - lo < fib.get()) fib.prev(); //�Ժ���ǰ˳����ң���̯O(1)��
         Rank mi = lo + fib.get() - 1; //ȷ������Fib(k) - 1�����
        (e < S[mi]) ? hi = mi : lo = mi + 1; //�ȽϺ�ȷ������ǰ���[lo, mi)�����(mi, hi)

	} //�ɹ����Ҳ�����ǰ��ֹ
  return --lo; //ѭ������ʱ��loΪ����e��Ԫ�ص���С�ȣ���lo - 1��������e��Ԫ�ص������

} //�ж������Ԫ��ʱ�����ܱ�֤������������ߣ�����ʧ��ʱ���ܹ�����ʧ�ܵ�λ��