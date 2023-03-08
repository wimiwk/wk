#include <stdio.h>
bool flag[10000010]; // 定义标记数组，且全局变量默认false
int main()
{
    int maxn;         // 范围
    long long re = 0; // 免得爆int
    scanf("%d", &maxn);
    for (int i = 2; i <= maxn; i++)
    {
        if (!flag[i]) // 如果i未被统计过，表明i是素数
        {
            re += i;                           // 添加素数
            for (int j = i; j <= maxn; j += i) // 将i能整除的 2i, 3i... ni标记未非素数
            {
                flag[j] = true;
            }
        }
    }
    printf("%lld", re);
    return 0;
}