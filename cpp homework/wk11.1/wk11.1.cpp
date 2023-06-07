#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
template <typename T>
T Max(T *a,int num) {
    sort(a,a+num);
	return a[num-1];
}
template <typename T>
T Min(T *a,int num) {
    sort(a,a+num);
	return a[0];
}
template <typename T>
double aver(T *a,int num) {
    double all=0;
    for (int i = 0; i < num; i++)
    {
        all+=(double)a[i];
    }
	return all/num;
}
int main( )
{
    int a[]={1,2,3,4,5,6,7,8,9,0};
    cout<<"MAX:"<<Max(a,10)<<endl;
    cout<<"MIN:"<<Min(a,10)<<endl;
    cout<<"average:"<<aver(a,10)<<endl;
    return 0;
}