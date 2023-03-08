#include <iostream>
using namespace std;
//数据类型
int main()
{
    short a = 32769;//short 短整型 2 Bytes -32768 to 32767 (-2^15 to 2^15-1)
    
    long b = 32769;//long 长整型 4 Bytes -2^31 to 2^31-1

    //int 整型 4 Bytes -2^31 to 2^31-1

    //long long 8 Bytes -2^63 to 2^63-1 

    cout << a << endl;

    cout << "a所占用的内存为；" << sizeof(a) << endl;

	system("pause");

	return 0;
}