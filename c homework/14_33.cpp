#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
int main()
{
	int n;
    scanf("%d",&n);
    char liu=getchar();
    for (int ii = 0; ii < n; ii++)
    {
        int ji[60],i=0,ou[60],j=0,o=0;
        char a[100];
        while (1)
        {
            a[i]=getchar();
            if (a[i]=='\n'&&i!=0) break;
            i++;
        }    
    int c=0,shu=0;
    for (int l = 0; l < i; l++)
    {
        if (a[l]<='9'&&a[l]>='0'&&c==0)
        {
            c=1;
            shu+=(a[l]-'0');
        }
        else if (c==1&&a[l]<='9'&&a[l]>='0') shu=shu*10+(a[l]-'0');
        if ((!(a[l]<='9'&&a[l]>='0'))&&c==1||(l==i-1&&a[l]<='9'&&a[l]>='0'))
        {
            c=0;
            int juj=shu%2;
            if (juj)
            {
                ji[j]=shu;
                j++;
            }
            if (!juj)
            {
                ou[o]=shu;
                o++;
            }
            shu=0;
        }  
    }
    std::sort(ji,ji+j);
    std::sort(ou,ou+o);
    for (int i = 0; i < j; i++)
    {
        printf("%d ",ji[i]);
    }
    for (int i = 0; i < o; i++)
    {
        printf("%d ",ou[i]);
    }
    printf("\n");
    }
	return 0;
}