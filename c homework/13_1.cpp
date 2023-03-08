#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int e[900],h[900],f[900],mua,nai;
void gcd(int n,int a,int g=0){
    int b=a%n;
    if (b==0)
    {
        g--;
        mua=g;
        f[g]=e[g];
        h[g]=n;
        for (int i = g-1; i >= 0; i--)
        {
            f[i]=f[i+1]*e[i]+h[i+1];
            h[i]=f[i+1];
        }
        if (mua%2==1)
        {
            printf("%d\n",f[0]);
        }
        else printf("%d\n",nai-f[0]);
        return;
    }
    e[g]=a/n;
    gcd(b,n,g+1);
}
int main() {
    int a,n;
    while (1)
    {
        scanf("%d%d",&a,&n);
        nai=n;
        if (a==n)
        {
            break;
        }
        gcd(a,n);
    }   
    return 0;
}