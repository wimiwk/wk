#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d",&m);
        int a[m],j,ii=0;
        for (int l = 0; l < m; l++)
        {
            scanf("%d",&a[l]);
            if (ii==j&&a[l]>j)
            {
                ii=a[l];
            }
            if (l==0)
            {
                j=a[0];
            }
            if (l==1)
            {
                if (a[l]<j)
                {
                    ii=j;
                    j=a[l];
                }
                else if (a[l]>=j)
                {
                    ii=a[l];
                }   
            }
            else if (a[l]<ii&&a[l]>j)
            {
                ii=a[l];
            }
            if (a[l]<j)
            {
                ii=j;
                j=a[l];
            }  
        }
        if (j==ii)
        {
            printf("ERROR\n");
        }
        else if (m==1)
        {
            printf("ERROR\n");
        }
        else printf("%d\n",ii);
    }   
    return 0;
}