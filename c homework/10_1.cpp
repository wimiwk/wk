#include <stdio.h>
#include <string.h>
#include <math.h>
int mystrstr(char a[], char b[]){
    int hhh;
    int lenb=strlen(b),lena=strlen(a);
        int n=0,i=0,co=0;
        for (int l=0; ; )
        {
            if (a[l]==b[i])
            {
                n++;
                i++;
                l++;
                if (i<lenb && l<lena)
                {
                    if (a[l]!=b[i])
                {
                    i=0;
                    l=++co;
                    n=0;
                }   
                }
            }
            else l++;
            if (n==lenb)
            {
                hhh=l-lenb;
                break;
            }
            if (l>=lena)
            {
                hhh=-1;
                break;
            }
        }
    return hhh;
}
int main(){
    char a[520],b[520];
    gets(a);
    gets(b);
    printf("%d",mystrstr(a,b)); 
    return 0;
}
