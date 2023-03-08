#include <stdio.h>
#include <math.h>
int y,x,b[102][102]={0},a[102][102],m=0;
void left(int y1,int x1);
void up(int y1,int x1);
void right(int y1,int x1);
void down(int y1,int x1);
int main() {
    scanf("%d%d",&y,&x);
    for (int i = 1; i <= y; i++)
    {
        for (int l = 1; l <= x; l++)
        {
            scanf("%d",&a[i][l]);
        }
    }
    for (int i = 1; i <= y; i++)
    {
        for (int l = 1; l <= x; l++)
        {
            printf("%d ",a[i][l]);
            b[i][l]=1;
        }
        printf("\n");
    }
    down(1,1);
    return 0;
}
void left(int y1,int x1){
    int x2;
    for (int i = x1; b[y1][i]!=0; i--)
    {
        printf("%d ",a[y1][i]);
        m++;
        if (m==y*x)
        {
            return;
        }
        b[y1][i]=0;
        x2=i;
    }
    down(y1+1,x2);
}
void up(int y1,int x1){
    int y2;
    for (int i = y1; b[i][x1]!=0; i--)
    {
        printf("%d ",a[i][x1]);
        m++;
        if (m==y*x)
        {
            return;
        }
        b[i][x1]=0;
        y2=i;
    }
    left(y2,x1-1);
}
void right(int y1,int x1){
    int x2;
    for (int i = x1; b[y1][i]!=0; i++)
    {
        printf("%d ",a[y1][i]);
        m++;
        if (m==y*x)
        {
            return;
        }
        b[y1][i]=0;
        x2=i;
    }
    up(y1-1,x2);
}
void down(int y1,int x1){
    int y2;
    for (int i = y1; b[i][x1]!=0; i++)
    {
        printf("%d ",a[i][x1]);
        m++;
        if (m==y*x)
        {
            return;
        }
        b[i][x1]=0;
        y2=i;
    }
    right(y2,x1+1);
}