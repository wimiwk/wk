#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>    
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    char cp[90];
    fgets(cp,101,stdin);
    for (int i = 0; i < n; i++)
    {
    char a[101];
    fgets(a,101,stdin);
    char *p=strchr(a,'SCU');
    int o=p-a-2;
    int mml=strlen(a);
    if (o<0||o>strlen(a)-3-1||o!=strlen(a)-o-3-1)           
    {
        printf("NO\n");
    }
    else{
        int ca=0;
        for (int i = 0; i < o; i++)
        {
            if (a[i]!='A')
            {
                printf("NO\n");
                ca=1;
                break;
            }
        }
        if (!ca)
        {
            for (int i = o+3; i < strlen(a)-1; i++)
            {
                if (a[i]!='A')
                {
                    printf("NO\n");
                    ca=1;
                    break;
                }
            }
            if (!ca)
            {
                printf("YES\n");
            }
        }
    }
    }
    return 0;
}