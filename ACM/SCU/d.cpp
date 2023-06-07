#include <iostream>
#include <climits>
using namespace std;

long long _minSquares(long long n) {
    if (n == 0) {
        return 0;
    }
    long long minSquares = INT_MAX;
    for (long long i = 1; i*i <= n; i++) {
        long long currSquares = 1 + _minSquares(n - i*i);
        if (currSquares < minSquares) {
            minSquares = currSquares;
        }
    }
    return minSquares;
}

int main() {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n;
        cin >> n;
        cout << _minSquares(n) << endl;
    }
    return 0;
}