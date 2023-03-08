#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    char a[501],b[501];
    gets(a);
    gets(b);
    int lenb=strlen(b),lena=strlen(a);
        int n=0,i=0;
        for (int l=0; ; )
        {
            if (a[l]==b[i])
            {
                n++;
                i++;
                l++;
            }
            else l++;
            if (n==lenb)
            {
                printf("YES");
                break;
            }
            if (l==lena)
            {
                printf("NO");
                break;
            }
        }
    return 0;
}