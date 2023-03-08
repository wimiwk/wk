#include <stdio.h>
#include <stdbool.h>
int main() {
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    bool a[n+1]={0};
        for (int y = 1; y <= n-2; y++)
        {
            int x=0,h=0;
            for (int l = 1; h!=3; l++)
            {
            for (int i = k; i <= n; i++)
            {
                if (a[i]!=1)
                {
                    x++;
                }
                if (x==m)
                {
                    a[i]=1;
                    h=3;
                    k=i+1;
                    break;
                } 
            }
            if (x<m)
            {
                k=1;
            }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i]==0)
            {
                printf("%d ",i);
            } 
        }
    return 0;
}