#include "counter.h"
counter::counter(int n)
{
    co=n;
}
counter::~counter()
{
}
void counter::cl(int n){
    if (!n)
    {
        cout<<zh<<endl;
        return;
    }
    zh=(zh+1)*2;
    n--;
    cl(n);
}