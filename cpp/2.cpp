#include <iostream>
using namespace std;

int main() {
	// ��������ʾ����ʽ��Ӧ�η���ϵ��
	// ����  coefficients[2] = 3.2 �ͱ�ʾ����ʽ�дη�Ϊ2����ϵ��Ϊ3.2 
	double coefficients[1001] = {0};
	// K1 �� K2������
	// K��ʾ�������Ķ���ʽ������ 
	int k1, k2;
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++) {
		int n;
		double a;
		scanf("%d%lf", &n, &a);
		// �ӵ���������� 
		coefficients[n] += a;
	}
	
	// �ѵڶ�������ʽ�ۼ���ȥ 
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++) {
		int n;
		double a;
		scanf("%d%lf", &n, &a);
		coefficients[n] += a;
	}
	
	int k = 0;
	// ͳ��һ���0�� 
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
