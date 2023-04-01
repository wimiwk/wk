#include "juz.h"
int main(){
    int m,n;
    cin>>m>>n;
    juz a(m,n);
    a.into();
    cin>>m>>n;
    juz b(m,n);
    b.into();
    ch(&a,&b);
    return 0;
}