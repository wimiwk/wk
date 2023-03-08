#include <stdio.h>
int main (){
    double a=3.141592653;
    printf ("%x",*((int*)(&a)));
	
	return 0;
}