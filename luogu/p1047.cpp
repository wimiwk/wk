#include <stdio.h>
int main() {
    int l,m;
    int g=0; 
    scanf("%d %d",&l,&m);
    int a[l+1];
    for (int i = 1; i <=l; i++)
    {
        a[i]=0;
    }    
    for (int i = 0; i < m; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        for (int f = u+1; f <=v+1; f++)
        {
            a[f]=1;
        }
    }
    for (int i = 1; i <=l+1; i++)
    {
        if (a[i]==0)
        {
            g++;
        }  
    }
    printf("%d\n",g);
    return 0;
}