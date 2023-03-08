#include <stdio.h>
int main() {
    int n,m;
    double s,s2;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int g=0;
        scanf("%d",&m);
        for (int i = 1; i <=m; i++)
        {
            s=m/i;
            s2=m*1.00/(i*1.00);
            if (s==s2)
            {
                g++;
            }            
        }       
        if (g==2)
        {
            printf("yes\n");
        }
        else printf("no\n");        
    }    
    return 0;
}