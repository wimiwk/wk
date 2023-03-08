#include <stdio.h>
int main() {
    int m[300],n[300],l[300];
    int s=1;
    for (int i = 123; i <= 333; i++)
    {
        int a=i,b=i*2,c=i*3;
        int a1=a/100%10,
        a2=a/10%10,
        a3=a%10,
        b1=b/100%10,
        b2=b/10%10,
        b3=b%10,
        c1=c/100%10,
        c2=c/10%10,
        c3=c%10;
        int h=0;
        for (int l = 1; l < 10; l++)
        {
            int g=0;
            if (a1==l)
            {
                g++;
            }  
            if (a2==l)
            {
                g++;
            }  
            if (a3==l)
            {
                g++;
            }  
            if (b1==l)
            {
                g++;
            }  
            if (b2==l)
            {
                g++;
            }  
            if (b3==l)
            {
                g++;
            }  
            if (c1==l)
            {
                g++;
            }  
            if (c2==l)
            {
                g++;
            }  
            if (c3==l)
            {
                g++;
            }  
            if (g==1)
            {
                h++;
            }   
        }
        if (h==9)
        {
            m[s]=a;
            n[s]=b;
            l[s]=c;
            s++;
        }     
    } 
    for (int i = 1; i <=s-1; i++)
    {
        printf("%d %d %d\n",m[i],n[i],l[i]);
    }   
    return 0;
}