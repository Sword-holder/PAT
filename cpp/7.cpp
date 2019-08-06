#include <iostream>
#include <climits>
using namespace std;

int main() {
	int N;
	cin >> N;
	int a[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	int max_sum = a[0], max_begin = 0;
	int current_sum = 0, begin = 0, end = 0;
	for (int i = 0; i < N; i++) {
		current_sum += a[i];
		// cout << current_sum << endl;
		if (current_sum > max_sum) {
			max_sum = current_sum;
			max_begin = begin;
			end = i;
		}
		if (current_sum < 0) {
			current_sum = 0;
			begin = i + 1;
		}
	}
	if (max_sum < 0) {
		cout  << "0 " << a[0] << " " << a[N - 1];
	}
	else {
		cout << max_sum << " " << a[max_begin] << " " << a[end];
	}
} 

