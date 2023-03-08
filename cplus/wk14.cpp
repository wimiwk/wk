#include <iostream>
using namespace std;
//比较运算符，以0,1 表示false和true
int main()
{
    int a = 10,b = 20;
    cout << (a == b) << endl;//有优先级，()内优先于后面的
    cout << (a != b) << endl;//！=  不等于
    cout << (a > b) << endl;
    cout << (a < b) << endl;
    cout << (a >= b) << endl;
    cout << (a <= b) << endl;
    

	system("pause");

	return 0;
}