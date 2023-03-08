#include <stdio.h>
int main() {
    int m,n;
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&n);
        for (int i = n; i >0; i--)
        {
            for ( int x=n-i ; x>0; x--)
            {
                printf(" ");
            }
            for (int y = 2*i-1; y>0; y--)
            {
                printf("*");
            }
            printf("\n");            
        }
    }    
    return 0;
}