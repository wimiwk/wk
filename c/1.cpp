#include <stdio.h>
#include <time.h>
int main (){
	double t0=clock();
	printf("%d\n",1+2);
	double t1=clock();
	printf("%f",t1-t0);
	return 0;
}