#include <iostream>
#include <iomanip>//用到setprecision
using namespace std;
//运算符
int main()
{
    int a1 = 10 , b1 = 3;
    cout << a1 + b1 << endl;
    cout << a1 * b1 << endl;
    cout << a1 / b1 << endl;//两个整数相除结果还是整数，小数抹去；除数不可为0
    cout << a1 % b1 << endl;//%取模运算本质是求余数;除数也不可为0

    double d1 = 0.5 , d2 = 0.22;
    cout << d1 / d2 << endl;
    //cout << d1 % d2 << endl;小数不可做取模运算

    int a = 10;
    ++a;
    cout << a << endl;
    int b = 10;
    b++;
    cout << b << endl;

    int a2 = 10 , b2 = ++a2 * 10;
    cout  << "b2 = " << b2 << endl;//前置递加先递加后运算表达式
    int a3 = 10 , b3 = a3++*10;
    cout << " b3 = " << b3 << endl;//后置递加先运算表达式后变量加1 

	system("pause");

	return 0;
}