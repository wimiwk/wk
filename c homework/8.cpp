#include <stdio.h>
int main() {
    int h;
    for (int i = 1; i <=9; i++)
    {
        for (int l = 1; l <=i; l++)
        {
            h=l*i;
            printf("%d",i);printf("*");printf("%d",l);printf("=");printf("%d",h);
            printf(" ");
        } 
        printf("\n");  
    }
    
    return 0;
}