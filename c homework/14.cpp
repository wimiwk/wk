#include <stdio.h>
int main() {
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int a[m*3][n*3];
    int y=1,x=1,z=1;
    a[y][x]=z;
    while (1)
    {
        z++;   
        if (x==n)
        {
            y++;
        }
        else x++;
        a[y][x]=z;
        if (y==m&&x==n)
        {
            break;
        }
        while (x!=1&&y!=m)
        {
            y++;
            x--;
            z++;
            a[y][x]=z;
        }
        if (y==m)
        {
            x++;
        }
        else
        {
            y++;
        }
        z++;
        a[y][x]=z;
        if (y==m&&x==n)
        {
            break;
        }
        while (y!=1&&x!=n)
        {
            y--;
            x++;
            z++;
            a[y][x]=z;
        }   
        if (y==m&&x==n)
        {
            break;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int l = 1; l <= n; l++)
        {
            printf("%d",a[i][l]);
            printf(" ");
        }  
        printf("\n"); 
    }
    return 0;
}