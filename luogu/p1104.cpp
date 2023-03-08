#include <stdio.h> 
#include <string.h>    
int main(){
    int n;
    scanf("%d",&n);
    int month[n],day[n],year[n];
    char str[n][50],f[n][50];
    int m[n+1]={0},d[n+1]={0},y[n+1]={0};  
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d",str[i],&year[i],&month[i],&day[i]);
        for (int ii = 0; ii <= i; ii++)
        {
            if ((year[i]>y[ii])||(year[i]==y[ii]&&month[i]>m[ii])||(year[i]==y[ii]&&month[i]==m[ii]&&day[i]>d[ii]))
            {
                for (int iii = i; iii > ii; iii--)
                {
                    y[iii]=y[iii-1];
                    m[iii]=m[iii-1];
                    d[iii]=d[iii-1];
                    strcpy(f[iii],f[iii-1]);
                }
                y[ii]=year[i];
                m[ii]=month[i];
                d[ii]=day[i];
                strcpy(f[ii],str[i]);
                break;
            }
        } 
    }
    for (int i = n-1; i >= 0; i--)
    {
        printf("%s\n",f[i]);
    }
    return 0;
}