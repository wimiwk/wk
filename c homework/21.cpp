#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        char a[520],b[520];
        scanf("%s %s",a,b);
        int lena=strlen(a),lenb=strlen(b);
        char c[520],d[520];
        int h=__max(lena,lenb);
        char e[520];
        for (int i = 0; i <= h+2; i++)
        {
            c[i]='0';
            d[i]='0';
            e[i]='0';
        }
        for (int i = 0; i < lena; i++)
        {
            c[lena-i-1]=a[i];
        }
        for (int i = 0; i < lenb; i++)
        {
            d[lenb-i-1]=b[i];
        }
        int waqu=0;
        for (int i = 0; i <= h; i++)
        {
            int k;
            k=(c[i]-'0')+(d[i]-'0');   
            if (waqu)
            {
                k++;
            }
            waqu=0;
            if (k>9)
            {
                k=k%10;
                waqu=1;
            }   
            e[i]=k+'0';
        }
        if (!(e[h]-'0'))
        {
            for (int i = h-1; i >= 0; i--)
            {
                printf("%c",e[i]);
            }
        }
        else{
            for (int i = h; i >= 0; i--)
            {
                printf("%c",e[i]);
            }  
        }   
        printf("\n");
    }   
    return 0;
}