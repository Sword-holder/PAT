#include <iostream>
using namespace std;

int main() {
	// 这个数组表示多项式对应次方的系数
	// 比如  coefficients[2] = 3.2 就表示多项式中次方为2的项系数为3.2 
	double coefficients[1001] = {0};
	// K1 和 K2是输入
	// K表示最后输出的多项式的项数 
	int k1, k2;
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++) {
		int n;
		double a;
		scanf("%d%lf", &n, &a);
		// 加到这个数组中 
		coefficients[n] += a;
	}
	
	// 把第二个多项式累加上去 
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++) {
		int n;
		double a;
		scanf("%d%lf", &n, &a);
		coefficients[n] += a;
	}
	
	int k = 0;
	// 统计一遍非0项 
	for (int i = 0; i <= 1000; i++) {
		if (coefficients[i] != 0.0) {
			k++;
		}
	}
	printf("%d", k);
	for (int i = 1000; i >= 0; i--) {
		if (coefficients[i] != 0.0) {
			printf(" %d %.1f", i, coefficients[i]);
		}
	}
	printf("\n");
	return 0;
} 
