#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    char a[1000][1000];
    int kk=0;
    while (gets(a[kk]))
    {
    if (strcmp(a[kk],"End of file")==0)
    {
        break;
    }
    int jj=0;
    for (int i = 0; i < strlen(a[kk]); i++)
    {
        if ((a[kk][i]-'0')<=9&&(a[kk][i]-'0')>=0)
        {
            int le=0;
        } 
        else if (a[kk][i]=='.')
        {
            int le=0;
        }
        else jj=1;
    }
    int x,b[310];
    b[0]=-1;
    int c=1,check=0,i=kk;
    for (int l=0;l<strlen(a[i]);l++)
    {
        if (a[i][l]=='.')
        {
            b[c]=l;
            c++;
        }  
    }
    b[c]=strlen(a[i]);
    for (int i = 1; i <= c; i++)
    {
        if (b[i]-b[i-1]==1)
        {
            jj=1;
            break;
        }   
    }
    if (jj==1)
    {
        printf("NO");
    }
    else if (c!=4)
    {
        printf("NO");
    }
    else {
        for (int ii = 1;ii <= c ; ii++)
        {
            int ss=0;
            for (int ll = b[ii]; ll > b[ii-1]+1; ll--)
            {
                ss=ss+(a[i][ll-1]-'0')*pow(10,b[ii]-ll);
            } 
            if (ss>255||ss<0)
            {
            check=1;
            break;
            }    
        } 
        if (check==1)
        {
            printf("NO");
        }
        else printf("YES");        
    }
    printf("\n"); 
    kk++; 
    }
    return 0;
}