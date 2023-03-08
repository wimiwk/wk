#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int x,y=0;
        scanf("%d",&x);
        for (int i = 0; i <= x&&i <= 3; i++)
        {
            for (int j = 0; j <= x-i&&j <= 3; j++)
            {
                for (int k = 0; k <= x-i-j&&k <= 6; k++)
                {
                    if (i+j+k==x)
                    {
                        y++;
                    }   
                }   
            }
        }
        printf("%d\n",y);
    }
    
    return 0;
}