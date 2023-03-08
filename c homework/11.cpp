#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n+10],b[n+10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d\n",a[0]);
    b[0]=a[0];
    for (int i = 1; i < n; i++)
    {
        int g=0;
        for (int l = 0; l < i; l++)
        {  
            if (a[i]<=b[l])
            {
                for (int h = i+1; h >= l+1; h--)
                {
                    b[h]=b[h-1];
                }  
                b[l]=a[i]; 
                g++;
                break;
            } 
        }
        if (g==0)
        {
            b[i]=a[i];
        } 
        for (int f = 0; f <= i; f++)
        {
            printf("%d ",b[f]);
        }    
        printf("\n");
    }
    return 0;
}