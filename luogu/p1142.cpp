#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    int b[n+2],c[n+2];
    int v=0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d",&b[i],&c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        double z[n];
        int h=0;
        for (int l = 1; l <= n; l++)
        {
            if (i!=l)
            {
                h++;
                double x,y;
                x=b[i]-b[l];
                y=c[i]-c[l];
                z[h]=x/y;
            }   
        }   
        int k=0;
        for (int l1 = 1; l1 <= h; l1++)
                {
                    for (int l2 = 1; l2 <= h; l2++)
                    {
                        if (l1!=l2)
                        {
                            if (z[l1]==z[l2])
                            {
                                k++;
                            }   
                        }  
                    }  
                } 
                int g=1.5+sqrt(k*1.00+0.25);
                if (g>v)
                {
                    v=g;
                }         
    }
    printf("%d",v);
    return 0;
}