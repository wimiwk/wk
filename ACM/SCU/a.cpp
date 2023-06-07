#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 300010;

int n, m;
char s[N], t[N];

int calc(char s[], int n, char t[], int m) {
    int res = 0;
    for (int i = 0, j = 0; i < n && j < m; ) {
        int k = i, l = j;
        while (k < n && s[k] == s[i]) k ++;
        while (l < m && t[l] == t[j]) l ++;
        res += max(k - i, l - j) - 1;
        i = k, j = l;
    }
    return res;
}

int main() {
    cin >> n >> m >> s >> t;

    int a = calc(s, n, t, m), b = calc(t, m, s, n);
    if (a < b) {
        swap(n, m);
        swap(s, t);
        swap(a, b);
    }

    int l = 0, r = n + m;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        bool flag = false;
        for (int i = 0, j = 0; i < n && j < m; ) {
            int k = i, l = j;
            while (k < n && s[k] == s[i]) k ++;
            while (l < m && t[l] == t[j]) l ++;
            int len = max(k - i, l - j);
            if (len >= mid) {
                flag = true;
                break;
            }
            if (i < n && j < m && s[i] == t[j]) {
                len = max(len, 2);
                if (len >= mid) {
                    flag = true;
                    break;
                }
            }
            i = k, j = l;
        }
        if (flag) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;

    return 0;
}