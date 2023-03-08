#include <stdio.h>
#include <string.h>
#include <math.h>
char a[30001][300];
int main(){
    int h=1,hh,oo=0;
    char c;
    for (int l=0;h==1;l++)
    {
    hh=l+1;
    int i=-1; 
    c=getchar(); 
    while(c!=' ')
    { 
        i++;
        a[l][i]=c;
        c=getchar();
        if (c=='\n')
        {
            h=0;
            break;
        }      
    }
    }
    int b[hh+1],bb[hh+1];
    for (int i = 0; i < hh; i++)
    {
        bb[i]=1;
    }
    int z;
    for (int i = 0; i < hh; i++)
    { 
        int x=1000;
        for (int l = 0; l < hh; l++)
        {
            int y=a[l][0];
            if (bb[l])
            {
            if (y<x)
            {
                x=y;
                z=l;
            } 
            else if (y==x)
            {
                for (int ii = 1; ii <= __max(strlen(a[z]),strlen(a[l])); ii++)
                {
                    int aa=a[z][ii],bbb=a[l][ii];
                    if (aa>bbb)
                    {
                        z=l;
                        break;
                    }  
                    if (aa<bbb)
                    {
                        break;
                    }
                }   
            }
            }
        }
        b[i]=z;
        bb[z]=0;
    }
    int scu=1;
    if (hh==1)
    {
        printf("%s %d",a[0],scu);
        printf("\n");
    }
    else 
    {
        for (int i = 0; i < hh; i++)
    {
        if (strcmp(a[b[i]],"")==0)
        {
            continue;
        }
        else if (i==hh-1)
        {
            printf("%s %d",a[b[i]],scu);
            printf("\n");
        }
        else if (strcmp(a[b[i]],a[b[i+1]])==0)
        {
            scu++;
        }
        else
        {
            printf("%s %d",a[b[i]],scu);
            printf("\n");
            scu=1;
        }   
    }  
    }
    return 0;
}