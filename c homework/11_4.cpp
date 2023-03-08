#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int f[520][520]={0};
        char a[520],b[520];
        scanf("%s %s",a,b);
        int lena=strlen(a),lenb=strlen(b);
        char c[520],d[520];
        int h=__max(lena,lenb);
        for (int i = 0; i <= h+2; i++)
        {
            c[i]='0';
            d[i]='0';
        }
        if (lena>=lenb)
        {
        for (int i = 0; i < lena; i++)
        {
            c[lena-i-1]=a[i];
        }
        for (int i = 0; i < lenb; i++)
        {
            d[lenb-i-1]=b[i];
        }
        }
        if (lena<lenb)
        {
        int kk;
        kk=lena;
        lena=lenb;
        lenb=kk;
        for (int i = 0; i < lena; i++)
        {
            c[lena-i-1]=b[i];
        }
        for (int i = 0; i < lenb; i++)
        {
            d[lenb-i-1]=a[i];
        }
        }
        int ma;
        for (int i = 0; i < lenb; i++)
        {
            int wei=i,gala=0;
            for (int l = 0; l <= lena; l++)
            {
                f[i][wei]=(c[l]-'0')*(d[i]-'0')%10+gala;
                gala=0;
                gala=(c[l]-'0')*(d[i]-'0')/10;
                wei++;
                ma=wei;
            }   
        }
        int e[520]={0},ex=0;
        for (int i = 0; i < ma; i++)
        {
            for (int l = 0; l < lenb; l++)
            {
                e[i]=e[i]+f[l][i];
            } 
            e[i]=e[i]+ex;
            ex=e[i]/10;
            e[i]=e[i]%10;
        }
        /*if (e[ma-1]==0)
        {
            ma=ma-1;
        }
        if (e[ma-1]==0&&e[0]==0)
        {
            ma=1;
        }*/
        int op=0;
        for (int i = ma-1; i >= 0; i--)
        {
            if (e[i])
            {
                op++;
            }
            if (op)
            {
                printf("%d",e[i]);
            }
            if (i==0&&op==0)
            {
                printf("0");
            }
            
        }
        printf("\n");
    }   
    return 0;
}