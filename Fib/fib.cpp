#include "fib.h"
__int64 Fib::fibI(int n) { //����Fibonacci���еĵ�n������棩��O(n)
    __int64 f = 1, g = 0; //��ʼ����fib(-1)��fib(0)
    while (0 < n--) { g += f; f = g - f; } //����ԭʼ���壬ͨ��n�μӷ��ͼ�������fib(n)
    return g; //����

}