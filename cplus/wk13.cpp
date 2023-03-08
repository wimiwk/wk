#include <iostream>
using namespace std;
//赋值运算符
int main()
{
    int a = 10;
    a +=2; //a = a + 2
    cout << "a =" << a <<endl;
    a -=2;
    cout << "a =" << a <<endl;

    a = 10;
    a *=2;
    cout << "a=" << a << endl;
    a /=2;
    cout << "a =" << a <<endl;

    a = 10;
    a %=3;
    cout << "a =" << a <<endl;


	system("pause");

	return 0;
}