#include <iostream>
#include <sstream>
using namespace std;

long long to_decimal(string N, int radix) {
	long long decimal = 0;
	int weight = 1;
	for (int i = N.length() - 1; i >= 0; i--) {
		int num;
		if (N[i] >= '0' && N[i] <= '9') {
			num = N[i] - '0';
		}
		else if (N[i] >= 'a' && N[i] <= 'z') {
			num = N[i] - 'a' + 10;
		}
		decimal += (weight * num);
		weight *= radix;
		// cout << "In itr : " << decimal << endl; 
	}
	return decimal;
}

int main() {
	string N1, N2;
	int tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	// 如果tag是2，先交换，N1的进制是确定的，N2的是不定的 
	if (tag == 2) {
		string temp = N1;
		N1 = N2;
		N2 = temp;
	}
	
	long long N3 = to_decimal(N1, radix);
	// cout << "N3 = " << N3 << endl;
	
	// 扫描整个数字，得到最大的那个digit，digit+1即为开始搜索的进制 
	int max_num = 0;
	for (int i = N2.length() - 1; i >= 0; i--) {
		int num;
		if (N2[i] >= '0' && N2[i] <= '9') {
			num = N2[i] - '0';
		}
		else if (N2[i] >= 'a' && N2[i] <= 'z') {
			num = N2[i] - 'a' + 10;
		}
		max_num = num > max_num ? num : max_num;
	}
	
	// cout << "max_num = " << max_num << endl; 
	
	// 遍历所有的进制，进行试探
	bool found = false;
	for (int i = max_num + 1; i <= 35 && !found; i++) {
		long long N4 = to_decimal(N2, i);
		// cout << "N4 = " << N4 << endl;
		if (N3 == N4) {
			found = true;
			cout << i;
		}
	}
	if (!found) {
		cout << "Impossible";
	}
} 
