#include <iostream>
#include <string>
using namespace std;
class Comparison {
public:
    int Compare(int a, int b) {
        return (a > b) ? a : b;
    }
    int Compare(char a, char b) {
        return abs(a - b);
    }
    string Compare(string a, string b) {
        return (a.length() > b.length()) ? a : b;
    }
};
int main() {
    Comparison c;
    int int1, int2;
    char char1, char2;
    string str1, str2;
    cin >> int1 >> int2;
    cout << c.Compare(int1, int2) << endl;
    cin >> char1 >> char2;
    cout << c.Compare(char1, char2) << endl;
    cin >> str1 >> str2;
    cout << c.Compare(str1, str2) << endl;
    return 0;
}