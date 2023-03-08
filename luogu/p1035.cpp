#include <stdio.h>
int main() {
    int k,n=1;
    double sn=0;
    scanf("%d",&k);
    for ( n = 1; sn < k; n++)
    {
        sn=sn+1/(n*1.00);
        if (sn>k)
        {
            printf("%d",n);
        }   
    }
    
    return 0;
}