#include <stdio.h>
#include <time.h>
int main() {
    double t0=clock();
    int n;
    scanf("%d",&n);
    int x1[n],y1[n];
    int lon[n],wide[n];
    int wocao=0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d %d",&x1[i],&y1[i],&wide[i],&lon[i]);
    }
    int x,y;
    scanf("%d %d",&x,&y);
    for (int i = 1; i <= n; i++)
    {
        for (int l =x1[i] ; l <=x1[i]+wide[i] ; l++)
        {   
            for (int h =y1[i] ; h <=y1[i]+lon[i] ; h++)
        {
            if (y==h&&x==l)
            {
                wocao=i;
            }    
        }
        }
    }
    if (wocao==0)
    {
        printf("%d",-1);
    }
    else printf("%d\n",wocao);
    double t1=clock();
    printf("%f",t1-t0);
    return 0;
}