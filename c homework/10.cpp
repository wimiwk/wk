#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d", &n);  
    for (int i = 0; i < n; i++) {
        int a,b,m,f,x;
        scanf("%d %d",&a,&b);  
        for (int l = 0;f!=a; l++)
        {
            m=pow(b,l);
            f=a%m;
            x=l-1;
        }  
        int h[x+1];
        for ( int v=x; v >= 0; v--)
        {
            m=pow(b,v);
            h[v]=a/m;
            a=a-h[v]*m;
        }     
        for (int v=x; v >= 0; v--)
        {
            printf("%d",h[v]);
        }      
        printf("\n");    
    }
    return 0;
}