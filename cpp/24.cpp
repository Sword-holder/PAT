#include <iostream> 
#include <sstream>
#include <cmath>

using namespace std;

bool is_palindromic(string num) {
	int length = num.length();
	for (int i = 0; i < length / 2; i++) {
		if (num[i] != num[length - i - 1]) {
			return false;
		}
	}
	return true;
}

string reverse(string num) {
	int length = num.length();
	for (int i = 0; i < length / 2; i++) {
		char temp = num[i];
		num[i] = num[length - i - 1];
		num[length - i - 1] = temp;
	}
	return num;
}


string str_plus(string a, string b) {
	string add;
	int carry = 0;
	int i = (int)a.length() - 1, j = (int)b.length() - 1;
	while (i >= 0 || j >= 0) {
		int d = carry;
		if (i >= 0) {
			d += (a[i] - '0');
			i--;
		}
		if (j >= 0) {
			d += (b[j] - '0');
			j--;
		}
		carry = 0;
		if (d >= 10) {
			carry = 1;
			d -= 10;
		}
		string temp = "0";
		temp[0] += d;
		add = temp + add;
	}
}

int main() {
	string N;
	int K;
	cin >> N >> K;
	int step;
	for (step = 0; step < K; step++) {
		cout << N << endl;
		if (is_palindromic(N)) {
			break;
		}
		else {
			N = str_plus(N, reverse(N));
		}
	}
	cout << N << endl;
	cout << step << endl;
}
