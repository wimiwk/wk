#include <stdio.h>
int main (){
    int n,m;
     scanf("%d%d",&n,&m);
     if((m-2*n)%2==1){
        printf("error 1\n");
        return 1;
     }
     int x,y;
     y=(m-2*n)/2;
     x=n-y;

     if (x<0 ||y<0){
        printf("error 2\n");
        return 2;
     }
     printf("x:%d,y:%d\n",x,y);
	
	return 0;
}