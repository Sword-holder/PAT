//
//  main.cpp
//  test
//
//  Created by 肖子洋 on 2019/8/4.
//  Copyright © 2019 肖子洋. All rights reserved.
//

#include <iostream>
#include <sstream>

// 返回输入的num是否为素数
bool is_prime(int num) {
    // 1不是素数啊！！！
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// 一个进制为radix的数转10进制
int to_dec(std::string num, int radix) {
    int result = 0;
    int weight = 1;
    for (int i = (int)num.length() - 1; i >= 0; i--) {
        result += weight * (num[i] - '0');
        weight *= radix;
    }
    return result;
}

// 一个十进制数转进制为radix的数
std::string to_radix(int num, int radix) {
    std::string result;
    while (num) {
        int r = num % radix;
        result += '0' + r;
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
    while (1) {
        int N, D;
        scanf("%d", &N);
        if (N < 0) {
            break;
        }
        scanf("%d", &D);
        // 判断N是否为素数，如果是，再把N以D进制进行倒转，然后判断倒转后的数值是否为素数；否则输出No
        if (is_prime(N)) {
            // 转化为N进制
            std::string reverse = to_radix(N, D);
            // 反转字符串
            int length = (int)reverse.length();
            for (int i = 0; i < length / 2; i++) {
                char temp = reverse[i];
                reverse[i] = reverse[length - 1 - i];
                reverse[length - 1 - i] = temp;
            }
            // 转化为10进制
            int reverse_dec = to_dec(reverse, D);
            // 判断是否为素数
            if (is_prime(reverse_dec)) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
        else {
            printf("No\n");
        }
    }
    
    return 0;
}
