#include <stdio.h>
int main() {
    int T,m,n;
    scanf("%d", &T);  
    for (int i = 0; i < T; i++) {
        scanf("%d%d", &m, &n);  
        int g=m;
        for ( int c = m; c <= n; c++)
        {
            int d=c%10,e=c/10%10,f=c/100%10;
            if (c==d*d*d+e*e*e+f*f*f)
            {
                printf("%d ",c);
            } 
            if (c!=d*d*d+e*e*e+f*f*f)
            {
                g++;
            }
            if (g==n+1)
            {
            printf("%d ",-1);
            }   
        }   
        printf("\n");
    }
    return 0;
}