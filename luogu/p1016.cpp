#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>    
#include <stdlib.h>
double d1,c,d2,p,yo=0,mon=0;
int n,co=0;
double di[8],pi[8],dp[8];
void toward(int co1,double yo1){
    int co2;
    double yo2;
    if (dp[co1+1]>c*d2)
    {
        printf("No Solution");
        return;
    }
    int mi=co1,mie;
    for (int i = co1+1; i<=n+1 ;i++)
    {
        if (di[i]-di[co1]<=yo1*d2)
        {
            if (pi[i]<pi[mi])
            {
                mi=i;
            }
        }
        else break;
    }
    if (mi-co1)//油够开到下一个油价更低的地方
    {
        co2=mi;
        yo2=yo1-((di[co2]-di[co1])/d2);
    }
    else{//油不够开到下一个油价更低的地方
        mie=co1+1;
        for (int i = co1+1; i<=n+1 ;i++)
        {
        if (di[i]-di[co1]<=c*d2)
        {
            if (pi[i]<pi[mi])
            {
                mi=i;
                break;
            }
            if (pi[i]<pi[mie])
            {
                mie=i;
            }
        }
        else break;
        } 
        if (mi-co1)//满油可以到下一个油价更低的地方
        {
            co2=mi;
            yo2=0;
            mon+=((di[co2]-di[co1])/d2-yo1)*pi[co1];
        }
        else{//满油到不了下一个油价更低的地方
            co2=mie;
            yo2=c-((di[co2]-di[co1])/d2);
            mon+=(c-yo1)*pi[co1];
        }
    }
    if (co2==n+1)
    {
        printf("%.2lf",mon);
        return;
    }
    toward(co2,yo2);
}
int main(){
    scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p,&n);
    di[0]=0;
    pi[0]=p;
    pi[n+1]=0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf",&di[i],&pi[i]);
        dp[i]=di[i]-di[i-1];
    }
    di[n+1]=d1;
    toward(co,yo);
    return 0;
}