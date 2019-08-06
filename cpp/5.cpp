#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += (s[i] - '0');
	}
	// stringstream是一个字符串流类，一般用于字符串和其它类型的转换
	// 一个stringstream对象重载了<< 和 >> 运算符
	// ss << obj 表示把obj对象输入到ss中
	// ss >> obj 表示把ss里的内容输出到对象中
	// 比如，要把一个字符串转化为整数，可以这么做： 
	//  string str = "12345";
	//  stringstream ss;
	//  ss << str;
	//  int num;
	//  ss >> num;
	// 这样，num的值就成了12345 
	stringstream ss;
	ss << sum;
	string sum_str = ss.str();
	string d[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 
	cout << d[sum_str[0] - '0'];
	for (int i = 1; i < sum_str.length(); i++) {
		cout << " " << d[sum_str[i] - '0'];
	}
	cout << endl;
	return 0;
} 
