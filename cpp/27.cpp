#include <iostream>

using namespace std;

// 把一个十进制数转化为13进制 
string to13radix(int num) {
	int first = num % 13;
	int second = num / 13;
	char first_ch, second_ch;
	if (first >= 10) {
		first_ch = 'A' + (first - 10);
	}
	else {
		first_ch = '0' + first;
	}
	if (second >= 10) {
		second_ch = 'A' + (second - 10);
	}
	else {
		second_ch = '0' + second;
	}
	string result = "00";
	result[0] = second_ch;
	result[1] = first_ch;
	return result;
}

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	string result = "#";
	result += to13radix(r);
	result += to13radix(g);
	result += to13radix(b);
	cout << result << endl;
} 
