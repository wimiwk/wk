#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>    
#include <stdlib.h>
#define N 100
int main(){
    FILE *score=fopen("score.txt","r");
    char str[N+1]={};
    int co=0,shu[14],all=0,mini=100,max=0;
    while( fgets(str, N, score) != NULL ) {
        shu[co]=(str[12]-'0')*10+(str[13]-'0');
        if (shu[co]<mini) mini=shu[co];
        if (shu[co]>max) max=shu[co];
        all+=shu[co];
        co++;
    }
    int pj=all/co;
    printf("最高分：%d\n",max);
    printf("最低分：%d\n",mini);
    printf("平均分：%d\n",pj);
    int fc=0;
    for (int i = 0; i < co; i++)
    {
        fc+=(shu[i]-pj)*(shu[i]-pj);
    }
    fc/=co;
    printf("标准方程：%d",fc);
    fclose(score);

    return 0;
}