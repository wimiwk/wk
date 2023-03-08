#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
int main() { 
    while (1)
    {
        char a[900],x;
        int scu=0;
        while (x=getchar())
        {
            if (x=='\n')
            {
                break;
            }
            if (x!=' ')
            {
                a[scu]=x;
                scu++;
            }
            
        }
        if (a[0]=='E'&&a[1]=='N'&&a[2]=='D')
        {
            break;
        }
        int lena=strlen(a),soda=0,amd=0,nvidia=0;
        for (int i = 0; i < lena; i++)
        {
            if (a[i]=='(')
            {
                if (soda==1)
                {
                    nvidia++;
                }
                soda++;
                if (soda>amd)
                {
                    amd=soda;
                } 
            }
            if (a[i]==')')
            {
                soda--;
            }
            if (soda==1&&a[i]>='a'&&a[i]<='z')
            {
                nvidia++;
            }
        }
        printf("%d %d\n",nvidia,amd);
    }
    return 0;
}