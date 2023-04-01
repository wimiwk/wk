#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[10];
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9];
    sort(a,a+10);
    cout<<endl<<a[0]<<endl<<a[1]<<endl<<a[2]<<endl<<a[3]<<endl<<a[4]<<endl<<a[5]<<endl<<a[6]<<endl<<a[7]<<endl<<a[8]<<endl<<a[9]<<endl;
}