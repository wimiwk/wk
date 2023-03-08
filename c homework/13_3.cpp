#include <stdio.h>
#include <math.h>
int n,a[900],count=1,c2=0;
void lej(int i){
    if (a[i]!=0)
    {
        if (a[i]-a[i-1]<=1&&a[i]-a[i-1]>=-1)
        {
            c2++;
        }
        return;
    }
    if (i==n+1)
    {
        c2++;
        return;
    }
    if (a[i-1]>=2)
    {
        a[i]=a[i-1]-1;
        lej(i+1);
        a[i]=0;
    }
    if (a[i-1]<n)
    {
        a[i]=a[i-1]+1;
        lej(i+1);
        a[i]=0;
    }
    a[i]=a[i-1];
    lej(i+1);
    a[i]=0;
    return;
}
int main() {
    while (1)
    {
    count=1;
    scanf("%d",&n);
    if (n==0) break;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    if (a[1]==0)
    {
        count=0;
        int t=1;
        for (int i = 1; i <= n; i++)
        {
            a[1]=i;
            for (int i = 1; i < n; i++)
            {
            if (a[i]!=0)
            {
                lej(i+1);
                t*=c2;
                c2=0;
            }
            }
            count+=t;
            t=1;
        }
    }
    else{
    for (int i = 1; i < n; i++)
    {
        if (a[i]!=0)
        {
            lej(i+1);
            count*=c2;
            c2=0;
        }
    }
    }
    printf("%d\n",count);
    }
    return 0;
}