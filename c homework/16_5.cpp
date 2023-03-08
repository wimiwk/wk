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
    char joe[10];
    scanf("%s",joe);
    student st[n];
    int co=0,cj[11],joe_nu,joe_cj,g;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%s",st[i].name,st[i].num,st[i].grade);
        if (!(!strcmp(st[i].grade,"n/a"))){
            g=atoi(st[i].grade);
            cj[co]=g;
            co++;
        }
        if (!strcmp(st[i].name,joe)){
            joe_nu=i;
            if (!(!strcmp(st[i].grade,"n/a"))) joe_cj=g;
        }
    }
    printf("%s %s %s ",st[joe_nu].name,st[joe_nu].num,st[joe_nu].grade);
    if (!strcmp(st[joe_nu].grade,"n/a")) printf("n/a");
    else{
        std::sort(cj,cj+co);
        for (int i = 0; i < co; i++)
        {
            if (cj[i]==joe_cj) printf("%d",co-i);
        }
    }
    return 0;
}