#include <iostream>

const int MOD = 998244353;


// 计算模逆元
int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}
int count_ABC_strings(int A, int B, int C, int K) {
    // 计算 x 的取值
    int x = A + B - C;
    // 计算满足条件的字符串个数
    int count = 1;
    for (int i = 1; i <= C; i++) {
        count = (count * (x - i + 1)) % MOD;
        count = (count * modInverse(i, MOD)) % MOD;
    }
    return count;
}

int main() {
    int A, B, C, K;
    std::cin >> A >> B >> C >> K;

    int result = count_ABC_strings(A, B, C, K);
    std::cout << result << std::endl;

    return 0;
}
