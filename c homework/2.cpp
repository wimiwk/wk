#include <stdio.h>
#include <math.h>
int main() {
    int a, b, c;
    double x1,x2,d, delt;
    while (scanf("%d,%d,%d", &a, &b, &c) == 3) {
    delt=(b*b)-(4*a*c);
    
    if ((a==0&&b==0)||delt<0){
        printf("x\n");
    }
    else if (a==0&&b!=0){
        x1=-1.00*c/b;
        printf("%.2lf\n",x1);
    }
    else if(a!=0&delt > 0){
        d=sqrt(delt);
        x1=(-b+d)/(2*a);
        x2=(-b-d)/2/a;
        printf("%.2lf %.2lf\n",x1,x2);
    }
    
     else if (a!=0&delt == 0){
        d=sqrt(delt);
        x1=(-b+d)/2/a;
        printf("%.2lf\n",x1);
    }
}
    return 0;
}





 //else if (delt<0){
   //     printf("x\n");
    //}
       // x1=(-b+d)/(2*a);
        //x2=(-b-d)/2/a;