#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>
int flag[1000];
int main(){
    int n;
    scanf("%d",&n);
    int a=0,aa[90000],bb[90000];
    if ((n%2==0)&&n>6)
    {
        for (int i = 3; i <= n/2; i+=2)
        {
            if (!flag[i]) // 如果i未被统计过，表明i是素数
            {                        
                for (int j = i*3; j <= n; j += i*2) // 将i能整除的 2i, 3i... ni标记未非素数
                {
                    flag[j] = true;
                }
            }
            if (!flag[i]&&!flag[n-i])
            {
                aa[a]=i;
                bb[a]=n-i;
                a++;
            }
        }
        for (int i = 0; i < a; i++)
        {
            printf("%d %d\n",aa[i],bb[i]);
        }
        
    }
    else printf("ERROR");
    return 0;
}