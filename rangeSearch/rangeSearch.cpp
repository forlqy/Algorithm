#include<cstdio>
#include<iostream>
using namespace std;
int s[500005];
int m, n;

//二分查找,返回不大于num的最后一个元素
int binSearch(int num, int lo, int hi) {
    while (lo < hi) {
		        int mi = (lo + hi) >> 1;
		      if (num < s[mi]) {
			         hi = mi;
			
		}
		else lo = mi + 1;
		
	}
	return --lo;
}
int getpartition(int lo, int hi) {
	     int mi = s[lo];
	    while (lo < hi) {
		         while (lo < hi && mi <= s[hi])hi--;
		        s[lo] = s[hi];
		         while (lo < hi && s[lo] <= mi)lo++;
		         s[hi] = s[lo];
		
	}
	    s[lo] = mi;
	   return lo;
	
}

//快速排序
void quicksort(int lo, int hi) {
	   if (lo < hi) {
	    int mi = getpartition(lo, hi);
		    quicksort(lo, mi - 1);
	     quicksort(mi + 1, hi);
	
	}

}
//注意输入输出太多，所以需要使用scanf,printf 加速输入输出
int main() {
	    scanf("%d%d", &m, &n);
	   for (int i = 0; i < m; i++) {
		      scanf("%d", &s[i]);
		
	}
	     quicksort(0, m - 1);
	   int a, b;
	    for (int i = 0; i < n; i++) {
		       scanf("%d%d", &a, &b);
		         int resA = binSearch(a - 1, 0, m);//小于a的最后一个位置
		        int resB = binSearch(b, 0, m);//b的最后位置
		       printf("%d \n", resB - resA);
		
	}
	    return 0;

}