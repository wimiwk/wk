#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        double x[1000],a;
        x[1]=1;
        scanf("%lf",&a);
        if (a<0)
        {
            printf("error\n");
        }
        else{
        for (int i = 1; i > 0; i++)
        {
            x[i+1]=(x[i]+a/x[i])/2;
            if (x[i+1]-x[i]<0)
            {
            if (x[i]-x[i+1]<0.00001)
            {
                printf("%.5lf\n",x[i+1]);
                break;
            } 
            }
            if (x[i+1]-x[i]>=0)
            {
            if (x[i+1]-x[i]<0.00001)
            {
                printf("%.5lf\n",x[i+1]);
                break;
            } 
            }
        } 
        }
    }   
    return 0;
}