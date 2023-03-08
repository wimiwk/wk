#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main() {
    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        int n;
        scanf("%d",&n);
        int a[n],b[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("--> ");
        for (int i = 0; i < n; i++)
        {
            printf("%d",a[i]);
            printf(" ");
        }
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            b[i]=0;
        }
        for (int i = 0; i < pow(2,n)-1; i++)
        {
            b[n-1]++;
            for (int i = n-1; i >= 0; i--)
            {
                if (b[i]==2)
                {
                    b[i]=0;
                    b[i-1]++;
                }
                else break;
            }
            printf("--> ");
            for (int i = 0; i < n; i++)
            {
                if (!b[i])
                {
                    printf("%d",a[i]);
                    printf(" ");
                }
            }
            printf("\n");
        }
        
    }
    return 0;
}