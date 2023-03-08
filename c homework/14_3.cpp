#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <algorithm>
int count=0,cu[900],amd[900],nb,max=0,max2;
int main(){
    int zu[900],co=0;
    char b[900];
    for (int i = 0; ; i++)
    {
        b[i]=getchar();
        if (b[i]=='/')
        {
            break;
        }        
    }   
    int noo=0;
    while (1)
    {
        char a=b[noo];
        noo++;
        if (a<='9'&&a>='0')
        {
            zu[co]=a-'0';
            co++;
        }
        else{
            if (co==1)
            {
                co=0;
                continue;
            }
            if (co>=2)
            {
                co--;
                int kk=0;
                for (int i = 0; i < co/2; i++)
                {
                    if (zu[i]!=zu[co-i]){
                        kk=1;
                        break;
                    }
                }
                if (kk==0)
                {
                for (int i = 0; i <= co; i++)
                {
                    cu[count]+=zu[i]*pow(10,co-i);
                }
                for (int i = 0; i < count; i++)
                {
                    if (cu[count]==cu[i])
                    {
                        amd[i]++;
                        if (amd[i]>max)
                        {
                            max=amd[i];
                            max2=i;
                        }
                        count--;
                    }
                    nb=count;
                }
                count++;
                }
            }
            co=0;
        }
    }
    std::sort(cu,cu+count+1);
    std::sort(amd,amd+count+1);
    for (int i = 0; i <= count; i++)
    {
        printf("%d %d",cu[i],amd[i]);
    }
    return 0;
 }
