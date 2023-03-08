#include <stdio.h> 
#include <string.h> 
#include <math.h>
int n[90];
char m[90][90],b[90];
int main(){
    char a;
    int co=0,c=0,k=0,zd=0,zds=0,jio,bio;
    while (1)
    {
        a=getchar();
        if ((a<='Z'&&a>='A'))
        {
        int shu=a;
        a=shu+32;
        }
        if (a>='a'&&a<='z')
        {
            k=1;
            b[co]=a;
            co++;
        }
        else if (k)
        {
            k=0;
            strcpy(m[c],b);
            for (int i = 0; i < c; i++)
            {
                if (!stricmp(m[i],m[c]))//strcasecmp
                {
                    n[i]++;
                    if (n[i]>zd)//||(n[i]==zd&&stricmp(m[c],m[zds])<0))//strcasecmp
                    {
                        zd=n[i];
                        zds=i;
                    }
                    else if (n[i]==zd)
                    {
                        for (int l = 0; l < __min(strlen(m[c]),strlen(m[zds])); l++)
                        {
                            jio=m[c][l],bio=m[zds][l];
                            if (jio>bio)
                            {
                                zd=n[i];
                                zds=i;
                                break;
                            }
                            if (m[c][l]==m[zds][l]) continue;
                            if (jio<bio) break;
                        }
                        
                    }      
                    c--;
                    break;
                } 
                else if (zd==0&&i==c-1)
                {
                    for (int l = 0; l < __min(strlen(m[c]),strlen(m[zds])); l++)
                        {
                            jio=m[c][l],bio=m[zds][l];
                            if (jio>bio)
                            {
                                zds=c;
                                break;
                            }
                            if (m[c][l]==m[zds][l]) continue;
                            if (jio<bio) break;
                        }
                }
                  
            }
            memset(b,0,strlen(b));
            co=0;
            c++;
        }
        if (a=='/')
        {
            break;
        }
    }
    printf("%s %d\n",m[zds],zd+1);
    return 0;
 }
