#include <stdio.h>
#include <stdbool.h>
bool b[10000000]={0};
int main() {
    int n,k,h;
    scanf("%d %d",&n,&k);
    int a[k+1];
    a[1]=1; 
    a[2]=a[1]*n+1;
    h=n;
    for (int i = 1; i <= n; i++)
    {
        b[i]=1;
    }
    if (k>2)
    {
    for (int i = 3; i <= k; i++)
    {
        a[i]=a[i-1]+n-1; 
    }
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d ",a[i]);
    }
    

    return 0;
}