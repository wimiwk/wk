#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r+1) / 2;
        cout << mid << endl;
        fflush(stdout);

        string s;
        cin >> s;
        if (s == "<") {
            r = mid - 1;
        } else {
            l = mid;
        }
    }

    cout << "! " << l << endl;
    fflush(stdout);

    return 0;
}