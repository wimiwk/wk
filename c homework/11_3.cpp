#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    int y,x,a[51][51];
    scanf("%d %d",&y,&x);
    for (int i = 1; i <= y; i++)
    {
        for (int l = 1; l <= x; l++)
        {
            scanf("%d",&a[i][l]);
        }
    }
    int xx[51],yy[51];
    int n;
    scanf("%d",&n);
    const int nn=n;
    for (int i = 0; i < nn; i++)
    {
        char xord[3];
        scanf("%s",xord);
        if (strcmp(xord,"SR")==0)
        {
            int x1,x2;
            scanf("%d",&x1);
            scanf("%d",&x2);
            for (int i = 1; i <= x; i++)
            {
                xx[i]=a[x1][i];
            }
            for (int i = 1; i <= x; i++)
            {
                a[x1][i]=a[x2][i];
            }
            for (int i = 1; i <= x; i++)
            {
                a[x2][i]=xx[i];
            }
        }
        if (strcmp(xord,"SC")==0)
        {
            int x1,x2;
            scanf("%d %d",&x1,&x2);
            for (int i = 1; i <= y; i++)
            {
                xx[i]=a[i][x1];
            }
            for (int i = 1; i <= y; i++)
            {
                a[i][x1]=a[i][x2];
            }
            for (int i = 1; i <= y; i++)
            {
                a[i][x2]=xx[i];
            }
        }
        if (strcmp(xord,"DR")==0)
        {
            int y1;
            scanf("%d",&y1);
            for (int i = y1; i < y; i++)
            {
                for (int l = 1; l <= x; l++)
                {
                    a[i][l]=a[i+1][l];
                }
            }
            y--;
        }
        if (strcmp(xord,"DC")==0)
        {
            int x1;
            scanf("%d",&x1);
            for (int i = x1; i < x; i++)
            {
                for (int l = 1; l <= y; l++)
                {
                    a[l][i]=a[l][i+1];
                }
            }
            x--;
        }
        if (strcmp(xord,"IR")==0)
        {
            int y1;
            scanf("%d",&y1);
            for (int i = y+1; i > y1; i--)
            {
                for (int l = 1; l <= x; l++)
                {
                    a[i][l]=a[i-1][l];
                }
            }
            y++;
            for (int i = 1; i <= x; i++)
            {
                a[y1][i]=0;
            }
        }
        if (strcmp(xord,"IC")==0)
        {
            int x1;
            scanf("%d",&x1);
            for (int i = x+1; i > x1; i--)
            {
                for (int l = 1; l <= y; l++)
                {
                    a[l][i]=a[l][i-1];
                }
            }
            x++;
            for (int i = 1; i <= y; i++)
            {
                a[i][x1]=0;
            }
        }
    }
    for (int i = 1; i <= y; i++)
    {
        for (int l = 1; l <= x; l++)
        {
            printf("%d",a[i][l]);
            if (l!=x)
            {
                printf(" ");
            }
        }
        if (i!=y)
        {
            printf("\n");
        }
    } 
    return 0;
}