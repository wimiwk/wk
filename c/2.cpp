#include <stdio.h>
#include <math.h>
const double PI = acos(-1);

int main (){
    double r,h,s;
    scanf("%lf%lf",&r,&h);
    s = 2 * PI * r * r + 2 * PI * r * h; 
    printf("%8.5f\n",s);
	
	return 0;
}