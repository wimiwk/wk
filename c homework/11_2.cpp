#include <stdio.h>
#include <string.h>
#include <math.h>
bool flag[10000];
int main(){
    int k,b[10000],co=0;
    scanf("%d",&k);
    for (int i = 2; i < 10000; i++)
    {
        if (!flag[i])
        {
            b[co]=i;
            co++;                           
            for (int j = i; j < 10000; j += i)
            {
                flag[j] = true;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        int a[10000],x,c[10000],coo=0;
        scanf("%d",&x);
        for (int i = 0;i<co; i++)
        {
            int jian=x%b[i];
            if (jian==0)
            {
                c[coo]=b[i];
                coo++;
                x=x/b[i];
                i=-1;
            }
            if (x==1) break;  
        }
        for (int i = 0; i <= coo-1; i++)
        {
            if (i==0)
            {
                printf("%d",c[i]);
            }
            else 
            {
                printf("*");
                printf("%d",c[i]);
            }
        }
        printf("\n");
    }   
    return 0;
}