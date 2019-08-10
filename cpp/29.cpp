#include <iostream>

using namespace std;

int main() {
	// i和j相当于两个指针，指向两个数组的 
	int i = 0, j = 0;
	int N1, N2;
	// 存放第一组数 
	cin >> N1;
	long a[N1];
	for (int t = 0; t < N1; t++) {
		scanf("%ld", &a[t]);
	}
	// 存放第二组数 
	cin >> N2;
	int end = (N1 + N2 - 1) / 2;
	
//	long temp, median;
//	
//	for (int t = 0; t < N2; t++) {
//		scanf("%ld", &temp);
//		if (i + j < end) {
//			if (i >= N1 || temp < a[i]) {
//				median = temp;
//				j++;
//			}
//			else {
//				median = a[i];
//				i++;
//			}
//		}
//	}
	
	// cout << "i = " << i << ", j = " << j << endl;
	cout << median; 
} 
