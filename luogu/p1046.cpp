#include <stdio.h>
#include <math.h>
int main() {
    int x,g=0;
    int a[10];
    scanf("%d %d %d %d %d %d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&a[10]);
    scanf("%d",&x);
    for (int i = 1; i <=10; i++)
    {
        if ((x+30)>=a[i])
        {
            g++;
        } 
    }
    printf("%d",g);
    
    
    return 0;
}