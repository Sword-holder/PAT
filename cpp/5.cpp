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
	// stringstream��һ���ַ������࣬һ�������ַ������������͵�ת��
	// һ��stringstream����������<< �� >> �����
	// ss << obj ��ʾ��obj�������뵽ss��
	// ss >> obj ��ʾ��ss������������������
	// ���磬Ҫ��һ���ַ���ת��Ϊ������������ô���� 
	//  string str = "12345";
	//  stringstream ss;
	//  ss << str;
	//  int num;
	//  ss >> num;
	// ������num��ֵ�ͳ���12345 
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
