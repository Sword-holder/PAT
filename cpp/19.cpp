#include <iostream>
#include <sstream>
using namespace std;

// 返回输入的num是否为回文数
bool is_palindromic(std::string num) {
    int length = (int)num.length();
    for (int i = 0; i < length / 2; i++) {
        if (num[i] != num[length - i - 1]) {
            return false;
        }
    }
    return true;
}

// 一个十进制数转进制为radix的数
std::string to_radix(int num, int radix) {
    std::string result;
    while (num) {
        int r = num % radix;
        if (r >= 10) {
        	result += 'A' + (r - 10);
		}
		else {
			result += '0' + r;
		}
        num /= radix;
    }
    int length = (int)result.length();
    for (int i = 0; i < length / 2; i++) {
        char temp = result[i];
        result[i] = result[length - 1 - i];
        result[length - 1 - i] = temp;
    }
    return result;
}


int main(int argc, const char * argv[]) {
    int N, D;
    scanf("%d%d", &N, &D);
    std::string num = to_radix(N, D);
    if (is_palindromic(num)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    
    if (num.length() > 0) {
        std::cout << num[0];
    }
    else {
        std::cout << "0";
    }
    for (int i = 1; i < num.length(); i++) {
        std::cout << " " << num[i];
    }
    
    return 0;
}

