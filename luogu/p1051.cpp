#include <stdio.h>
#include <string.h>
int main() {
    int N,m,n,m2,n2,lw,all,all2=0,all3=0;
    scanf("%d",&N);
    int a[N];
    char s[20],x[20];
    char ganb,xib;
    a[0]=0;
    for (int i = 1; i <= N; i++)
    {
        all=0;
        scanf("%s %d %d %c %c %d",&s,&m,&n,&ganb,&xib,&lw);
        if (n>80 && ganb=='Y')
        {
            all=all+850;
        } 
        if (xib=='Y'&&m>85)
        {
            all=all+1000;
        }
        if (m>90)
        {
            all=all+2000;
        }
        if (m>85&&n>80)
        {
            all=all+4000;
        }
        if (m>80&&lw>=1)
        {
            all=all+8000;
        }
        a[i]=all;
        all3=all3+all;
        if (a[i]>all2)
        {
            all2=a[i];
            strcpy(x,s);
        }         
    }   
    printf("%s\n%d\n%d\n",x,all2,all3);
    return 0;
}