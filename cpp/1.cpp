#include <iostream>
#define BUFFER_SIZE 256

using namespace std;

string format(int num) {
    // 先把数字处理成char数组
    char buffer[BUFFER_SIZE];
    int length = 0;
    bool isMinus = 0;
    if (num < 0) {
        num = -num;
        isMinus = 1;
    }
    if (num == 0) {
        buffer[length++] = '0';
    }
    else {
        int count = 0;
        while(num) {
            if (count != 0 && count % 3 == 0) {
                buffer[length++] = ',';
            }
            count++;
            buffer[length++] = num % 10 + '0';
            num /= 10;
        }
    }
    for (int i = 0; i < length / 2; i++) {
        // 交换
        int temp = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = temp;
    }
    // 组成最后的字符串
    string formatStr = "";
    if (isMinus) {
        formatStr += "-";
    }
    for (int i = 0; i < length; i++) {
        formatStr.append(1, buffer[i]);
    }
    
    return formatStr;
}

int main(int argc, const char * argv[]) {
    int a, b;
    scanf("%d%d", &a, &b);
    int sum = a + b;
    string s = format(sum);
    cout << s << endl;
    return 0;
}
