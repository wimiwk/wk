#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>    
#include <stdlib.h>
struct student{
    char name[10];
    char num[30];
    char grade[10];
};
int main(){
    int n;
    scanf("%d",&n);
    student st[n];
    int ma=0,mi=101,maxi,mina;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%s",st[i].name,st[i].num,st[i].grade);
        if (!strcmp(st[i].grade,"n/a")) continue;
        else{
            int g=atoi(st[i].grade);
            if (g>ma)
            {
                ma=g;
                maxi=i;
            }
            else if (g==ma)
            {
                for (int l = 0; l < 10; l++)
                {
                    
                    if (st[maxi].name[l]<st[i].name[l]) break;
                    if (st[maxi].name[l]>st[i].name[l])
                    {
                        maxi=i;
                        break;
                    }
                }
            }
            if (g<mi)
            {
                mi=g;
                mina=i;
            }
            else if (g==mi)
            {
                for (int l = 0; l < 10; l++)
                {
                    
                    if (st[mina].name[l]>st[i].name[l]) break;
                    if (st[mina].name[l]<st[i].name[l])
                    {
                        mina=i;
                        break;
                    }
                }
            }
        }
    }
    printf("%s %s\n",st[maxi].name,st[maxi].num);
    printf("%s %s\n",st[mina].name,st[mina].num);
    return 0;
}