#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            reverse(a + i, a + i + 2);
            ans++;
        }
    }
    if (is_sorted(a, a + n)) {
        cout << ans << endl;
        return 0;
    }
    rotate(a, a + 1, a + n);
    ans++;
    while (!is_sorted(a, a + n)) {
        rotate(a, a + 1, a + n);
        ans++;
    }
    cout << ans << endl;
    return 0;
}