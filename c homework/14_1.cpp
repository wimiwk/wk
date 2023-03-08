#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
    int a ,b, c;
    scanf("%d%d%d",&a ,&b,&c);
    if((a*a+b*b==c*c||b*b+c*c==a*a||c*c+a*a==b*b)&&(a+b>c&&a+c>b&&b+c>a))
    { printf("Yes\n"); }
     else
    { printf("No\n");}
    }
     return 0;
 }
