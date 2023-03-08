#include <iostream>
#include <iomanip>//用到setprecision
using namespace std;
//实型（浮点型）用于表示小数
//float 单精度 4 Bytes 7位有效数字
//double 双精度 8 Bytes 15 to 16 位有效数字
int main()
{
    float f1 = 3.14f;//不加f会默认其为double
    cout << " f1 = " << f1 << endl;
    double d1 = 3.141592653;
    cout << fixed << setprecision (6) << " d1 = " << d1 << endl;
    cout << " float 占用的内存空间为；" << sizeof(d1) << endl;
    float f2 = 3e2;//3*10^2;
    float f3 = 3e-2;
    cout << " f2 = " << f2 << endl;
    cout << " f3 = " << f3 << endl;
	system("pause");
	return 0;
}