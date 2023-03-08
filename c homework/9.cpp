#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int z=a/b;
        int d[c+10],h[c+10];
        printf("%d.",z);
        for (int l = 0; l <=c; l++)
        {
            a=a%b*10;
            d[l]=a/b;
        }
        if (d[c]>=5)
            {
                if (d[c-1]<9)
                {
                    h[c]=d[c-1]+1;
                }
                if (d[c-1]==9)
                {
                    d[c-1]+=1;
                    h[c]=0;
                }    
            }  
        if (d[c]<5)
        {
            h[c]=d[c-1];
        }
         
        for (int i = c-2; i >= 0; i--)
        {
            if (d[i+1]==10&&d[i]<9)
            {
                h[i+1]=d[i]+1;
            }
            if (d[i+1]==10&&d[i]==9)
            {
                h[i+1]=0;
                d[i]+=1;
            }
            if (d[i+1]!=10)
            {
                h[i+1]=d[i];
            }   
        }
        for (int i = 1; i <= c; i++)
        {
            printf("%d",h[i]);
        }
        printf("\n");
    }   
    return 0;
}