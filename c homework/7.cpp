#include <stdio.h>
int main() {
    int T,m,n,h;
    double x,y;
    int a[50];
    scanf("%d",&T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d",&m,&n);
        int o=0;
        for (int f = 1; f <= m; f++)
        {
            //x=m/f;
            //y=m*1.00/(f*1.00);
            x=m%f;
            if (x==0)
            {
                o++;
                a[o]=f;    
            }           
        }
        for (int l = 1; l <=o; l++)
        {
            //x=n/a[l];
            //y=n*1.00/(a[l]*1.00);
            x=n%a[l];
            if (x==0)
            {
                h=a[l];
            }   
        } 
        printf("%d\n",h);         
    }  
    return 0;
}