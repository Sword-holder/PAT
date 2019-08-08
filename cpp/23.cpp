#include <iostream>

using namespace std;

int main() {
	string num;
	cin >> num;
	// 这个表是用于记录有哪些数字 
	int digits[10] = {0};
	
	for (int i = 0; i < num.size(); i++) {
		digits[num[i] - '0'] += 1;
	}
	
	// 对字符串进行乘2 
	string double_num;
	int carry = 0;
	for (int i = (int)num.size() - 1; i >= 0; i--) {
		int d = num[i] - '0';
		d *= 2;
		d += carry;
		carry = 0;
		if (d >= 10) {
			carry = 1;
			d -= 10;
		}
		string temp = "0";
		temp[0] += d;
		double_num = temp + double_num;
	}
	if (carry == 1) {
		double_num = '1' + double_num;
	}
	
	// 检查是否是原数的排列组合 
	for (int i = 0; i < double_num.size(); i++) {
		digits[double_num[i] - '0'] -= 1;
	}
	bool fun = true;
	for (int i = 0; i < 10; i++) {
		if (digits[i] != 0) {
			fun = false;
		}
	}
	
	// 输出结果 
	if (fun) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
	cout << double_num << endl;	
} 
