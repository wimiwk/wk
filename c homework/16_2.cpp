#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>    
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int c=0;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d",&a);
        c+=a;
    }
    printf("%.2lf",c*1.00/(n*1.00));
    return 0;
}