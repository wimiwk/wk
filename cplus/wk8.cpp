#include <iostream>
using namespace std;

int main()
{
    /*常用转义字符
    换行符 \n   可替代<< endl;
    反斜杠 \\   不可cout<<"\"<<endl
    水平制表符 \t  其前面的字符加上后面的空格一共占8个位置   */

    cout << "hello world\n"; 

    cout << "\\" << endl;

    cout << "aaa\thello world\n";
    cout << "aaaaa\thello world\n";
    cout << "a\thello world\n";
    // \t 可以整齐化其后的字符

	system("pause");

	return 0;
}