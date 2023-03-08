#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int x,y=1;
        scanf("%d",&x);
        for (int i = 1; i >= 0; i++)
        {
            if (x/10==0)
            {
                printf("%d\n",y);
                break;
                
            }
            else
            {
            x=x/10;
            y++;
            }
        }  
    }   
    return 0;
}