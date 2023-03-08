#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>    
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int c=0,co=0;
    for (int i = 0; i < n; i++)
    {
        char a[20];
        scanf("%s",&a);
        if (!strcmp(a,"n/a")) continue;
        else{
            co++;
            c+=atoi(a);
        }
    }
    if (co==0) printf("n/a");
    else printf("%.2lf",c*1.00/(co*1.00));
    return 0;
}