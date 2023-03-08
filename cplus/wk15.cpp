#include <iostream>
using namespace std;
//逻辑运算符
//  ! 非      ！a：如果a为假，则！a为真
//  && 与     a&&b：如果a和b都真，则为真，否则皆假
//  || 或     a||b：如果a和b有一个真，则结果为真，二者皆假时，结果为假
int main()
{
    int a = 10;
    cout << !a << endl;//C++中除了0都为真，所以！a=0非真为假
	system("pause");

	return 0;
}