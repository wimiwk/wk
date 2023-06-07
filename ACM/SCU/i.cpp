#include <iostream>
#include <vector>
using namespace std;
long long count[1000000];
int main() {
    int n;
    cin >> n;
    long long min=0,maxi=2147483646;
    for (int i = 0; i < n; i++) {
        int si, ti;
        cin >> si >> ti;
        for (int j = si; j < si+ti; j++) {
            count[j]++;
        }
        if (si<maxi)
        {
            maxi=si;
        }
        if (si+ti>min)
        {
            min=si+ti;
        }
    }
    int ans[n];
    for (int i = maxi; i < min; i++) {
        if (count[i] > 0 && count[i] <= n) {
            ans[count[i]-1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}