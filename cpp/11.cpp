#include <iostream>
#include <climits>
using namespace std;

int main() {
	// 这题贼简单，懒得写注释了 
	double a[9];
	double profit = 1.0;
	char code[3] = {'W', 'T', 'L'}; 
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++) {
		double max = INT_MIN;
		int max_id = -1;
		for (int j = 0; j < 3; j++) {
			if (a[i * 3 + j] > max) {
				max = a[i * 3 + j];
				max_id = j;
			}
		}
		profit *= max;
		cout << code[max_id] << " ";
	}
	printf("%.2f", (profit * 0.65 - 1) * 2);
	
	return 0;
} 
