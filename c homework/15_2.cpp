#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>
int main(){
    int n,a[90],b[90];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&b[i]);
        a[i]=b[i];
        if (b[i]<0)
        {
            a[i]=0-b[i];
        }
    }
    std::sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
        if (a[n-1]+b[i]==0)
        {
            a[n-1]=b[i];
        }   
    }
    printf("%d",a[n-1]);
    return 0;
 }
