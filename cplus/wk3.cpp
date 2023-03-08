#include <iostream>
using namespace std;
//常量规定后不可更改
//#define为宏常量，在文件上方定义
//const修饰变量为常量，在变量定义前加const
#define Day 7//定义一个标识符，表示常量，不占内存

int main()
{
    cout << "一周共用；" << Day << "天" << endl ;

    const int month = 12;

    cout << "一年共有：" << month << "个月份" << endl;

	system("pause");

	return 0;
}