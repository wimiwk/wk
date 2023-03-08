#include<stdio.h>  
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    long long a[90][90],b[90][90],c[90][90];
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d",&a[l][i]);
            b[l][i]=a[l][i];
            c[l][i]=0;
        }
    }
    for (int i = 0; i < k-1; i++)
    {
        for (int l = 1; l <= n; l++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int ii = 1; ii <= n; ii++)
                {
                    c[l][i]+=a[l][ii]*b[ii][i];
                }
            }
        }
        for (int l = 1; l <= n; l++)
        {
            for (int i = 1; i <= n; i++)
            {
                a[l][i]=c[l][i];
                c[l][i]=0;
            }
        }
    }
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%lld ",a[l][i]);
        }
        printf("\n");
    }
    return 0;
 }
