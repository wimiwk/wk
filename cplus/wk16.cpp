#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a=10.99999999999999;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    //        参数1            参数2
    cout << a << endl;
    /*ios_base::
        参数1   boolalpha 输入or输出布尔值
                oct 八进制表示数值
                dec 十进制
                hex 十六进制
                left 左对齐
                right 右对齐
                fixed 正常方法表示浮点数
                scientific 科学计数法表示浮点数
    可以cout << scientific << a << endl;
    */
    cout << fixed << setprecision(10) << a <<endl;//fixed用来消除浮点数的科学计数法
   //上一行使用后，后面的cout全是小数点后6位
	return 0;
}