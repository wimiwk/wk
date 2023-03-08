#include <stdio.h>
int main() {
    int n,c;
    scanf("%d",&n);
    double a[n],b;
    for (int i = 1; i <= n; i++)
    {
        a[i]=(n*1.00)/(i*1.00);
        b=(n/i)*1.00;
        if (a[i]==b)
        {
            double d[i];
            int x=0;
            for (int e = 1; e <= i; e++)
            {                
                d[e]=(n*1.00)/(e*1.00);
                b=(n/e)*1.00;
                if (d[e]==b)
                {
                    x++;
                }
            }
            if (x==2)
            {
                c=a[i];
            } 
        }
    }
    printf("%d",c);
    return 0;
}