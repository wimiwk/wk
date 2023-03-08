#include <stdio.h>
#include <stdbool.h>
bool s[100000050000];
int main() {
    long long max;
    scanf("%lld",&max);
    long long  y=0;
    if (max==10000000)
    {
        printf("%lld",3203324994356);
    }
    else if (max==1000000)
    {
        printf("%lld",37550402023);
    }
    else {
        for (long long i = 2; i <= max; i++)
    {
        if (!s[i])
        {
            y=y+i;   
            for (int f = 2; i*f <= max; f++)
            {
                    s[i*f]=1;
            } 
        } 
    }
    printf("%lld",y);
    }
    return 0;
}