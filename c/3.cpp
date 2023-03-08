#include <stdio.h>
#include <math.h>
//翻转输出
int main (){
	int x;
    scanf("%d",&x);

    int a,b,c;
    a=x%10;
    b=x/10%10;
    c=x/100%10;
    printf("%d%d%d",a,b,c);

	return 0;
}