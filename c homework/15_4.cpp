#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>
int main(){
    int m,mini=0,maxi=0;
    scanf("%d",&m);
    int co[m]={0};
    char zm[m];
    for (int l = 0; l < m; l++)
    {
        char a[6];
        int zf=1;
        scanf("%s",a);
        for (int i = 0; i < 4; i++)
        {
            if (a[i]<='9'&&a[i]>='0') co[l]=co[l]*10+(a[i]-'0');
            else{
                if (a[i]=='-') zf=0;
                else{
                    if(!zf) co[l]=0-co[l]; 
                    zm[l]=a[i];
                    if (co[l]>maxi) maxi=co[l];
                    if (co[l]<mini) mini=co[l];
                    break;
                }
            }
            if (i==strlen(a)-1){
                zm[l]='+';
                if(!zf) co[l]=0-co[l];
                if (co[l]>maxi) maxi=co[l];
                if (co[l]<mini) mini=co[l];
                break;
            }
        }
    }
    char alo[m][maxi],plo[m][-mini];
    for (int i = 0; i < m; i++)
    {
        memset(alo[i],0,sizeof(alo[i]));
        memset(plo[i],0,sizeof(plo[i]));
    }
    for (int i = 0; i < m; i++)
    {
        if (co[i]>0)
        {
            for (int l = 0; l < co[i]; l++)
            {
                alo[i][maxi-l-1]=zm[i];
            }
        }
        if (co[i]<0)
        {
            for (int l = 0; l < -co[i]; l++)
            {
                plo[i][l]=zm[i];
            } 
        }                                              
    }
    for (int i = 0; i < maxi; i++)
    {
        for (int l = 0; l < m; l++)
        {
            if (alo[l][i]=='\0')
            {
                printf("  ");
            }
            else printf("%c ",alo[l][i]);
        }
        printf("\n");
    }
    for (int i = 0; i < 2*m-1; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < -mini; i++)
    {
        for (int l = 0; l < m; l++)
        {
            if (plo[l][i]=='\0')
            {
                printf("  ");
            }
            else printf("%c ",plo[l][i]);
        }
        printf("\n");
    }
    
    return 0;
}