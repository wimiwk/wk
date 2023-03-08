#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    //char *a=(char*)malloc(strlen("012345689+-=")+1);分配内存
    char *a="012345689+-=",x='1';
    int k=strchr(a,x)-a;
    printf("%d",k);
    return 0;
}