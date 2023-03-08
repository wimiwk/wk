#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char s[8];
void erjin(int a){
    int guy;
    for (int i = 0; i < 8; i++)
    {
        s[i]='0';
    }
    if (a==0)
    {
        return;
    }
    if (a==1)
    {
        s[7] = '1';
        return;
    }
    if (a==128)
    {
        s[0]='1';
        return;
    }  
    for (int i = 0;; i++)
    {
        
        if (pow(2,i)>a)
        {
            guy=i;
            break;
        } 
    }
    for (int i = 8-guy; i <= 7 ;i++)
    {
        s[i]=a/pow(2,7-i)+'0';
        a=a%(int)pow(2,7-i);
    }
}
int main() {
    int m;
    char b[90][8];
    scanf("%d",&m);
    int lenm=m/8;
    int a[lenm];
    for (int i = 0; i < lenm; i++)
    {
        scanf("%d",&a[i]);
        erjin(a[i]);
        strcpy(b[i],s);
    }
    int l=0;
    char omiga[900];
    for (int i = 0; i < lenm; i++)
    {
        for (int ii = 0; ii < 8; ii++)
        {
            omiga[l]=b[i][ii];
            l++;
        }
    }
    char nik=omiga[0];
    int count=1,aa[90]={0},le=0;
    for (int i = 1; i < strlen(omiga); i++)
    {
        if (omiga[i]==nik)
        {
            count++;
        }
        if (omiga[i]!=nik||i==strlen(omiga)-1)
        {
            if (nik=='1')
            {
                aa[le]=aa[le]+128;
            }
            aa[le]=aa[le]+count;
            le++;
            count=1;
            nik=omiga[i];
        }
    }
    for (int i = 0; i < le; i++)
    {
        printf("%d",aa[i]);
        printf(" ");
    }
    printf("\n");
    return 0;
}