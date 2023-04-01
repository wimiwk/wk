#include "cnct.h" 
dwu::dwu(char c,char v,char b)
{
    a[0]=c;
    a[1]=v;
    a[2]=b;
}
dwu::~dwu()
{
}
void cn(dwu *j,dwu *y){
    int h[3];
    h[0]=2;
    h[1]=0;
    h[2]=1;
    for (int i = 0; i < 3; i++)
    {
        cout<<j->a[i]<<" VS "<<y->a[h[i]]<<endl;
    }
}