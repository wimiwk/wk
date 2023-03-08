#include <stdio.h> 
#include <string.h>    
int main(){
    int m,n,c=0;
    scanf("%d%d",&m,&n);
    char mm[m][50],nn[n][50];
    getchar();
    for (int i = 0; i < m; i++)
    {
        gets(mm[i]);
    }
    for (int i = 0; i < n; i++)
    {
        gets(nn[i]);
        for (int ii = 0; ii < m; ii++)
        {
            if (!strcmp(nn[i],mm[ii]))
            {
                c++;
            }
        }    
    }
    printf("%d",c);
    return 0;
}