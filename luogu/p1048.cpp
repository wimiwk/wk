#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int T,M,c=0;
    scanf("%d %d",T,M);
    int a[M],b[M];
    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d",a[i],b[i]);
    }
    srand(time(0));
    for (int i = 0; i < 999999999999; i++)
    {
        int n=rand();
        int m=rand();
        if (n<=M)
    {
        for (int i = 0; i < n; i++)
        {
            c=c+a[i];
        }  
    }  
    }
    
    
    return 0;
}