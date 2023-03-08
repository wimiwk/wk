#include <stdio.h>
int main() {
    int m;
    scanf("%d",&m);
    for (int s = 0; s < m; s++)
    {
        int a[100000]={0};
        for (int i = 1; i > 0; i++)
        {
            int hh;
            scanf("%d",&hh); 
            a[hh]=1;
            if (hh==0)
            {
                break;
            }    
        }
        for (int i = 1; ; i++)
        {
            if (!a[i])
            {
                printf("%d\n",i);
                break;
            }  
        } 
    }   
    return 0;
}