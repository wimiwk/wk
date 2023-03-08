#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(0));
    for (int i = 0; i < 999999; i++)
    {
        int n=rand(),m=rand();

        if (n<100&&n>0)
        {
            printf("%d\n",n);
            printf("%d\n",m);
        }
    } 
    return 0;
}