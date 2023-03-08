#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d", &n);  
    for (int i = 0; i < n; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        for (int i = 0; i <= x; i++)
        {
            int d=y-i*3;
            for (int l = 0; l <= y-i; l++)
            {
                int e=d-l*2;
                if (i+l+e==x)
                {
                    printf("%d %d %d\n",i,l,e);
                }     
            }   
        }  
    }
    return 0;
}