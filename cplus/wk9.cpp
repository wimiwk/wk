#include <iostream>
#include <string>//用C++风格字符串时要包含这个头文件
using namespace std;
//字符串型
//C风格字符串；char 变量名[]="字符串值"  不用[]只能用于字符，不可字符串
//C++风格字符串；string 变量名 = "字符串值"
int main()
{
    char str[] = "hello world";

    string str2 = "hello world";

    cout << str << endl;

    cout << str2 << endl;

	system("pause");

	return 0;
}