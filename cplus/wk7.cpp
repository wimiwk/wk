#include <iostream>
using namespace std;
//字符型变量
//char 注意单引号,且单引号内只能有一个字符
int main()
{
    char ch = '.';//只能一个字符

	//char 只占1个字节

	char ch2 = 'b';

	cout << ch << endl;

	cout << (int)ch2 << endl;//强制将字符型变量变为整型变量，输出字符对应的ASCII码

	/*需记住的ASCII码；a=97,其他字母累加
	                  A=65,其他字母累加*/

	system("pause");

	return 0;
}