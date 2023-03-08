#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        char a[3000],eqh='=',b,x;
        scanf("%s",&a);
        int len=strlen(a),c=0;
        int eq=strchr(a,eqh)-a,xi=0;
        for (int i = 0; i < len; i++)
        {
            if (((a[i]-'0'>9)||(a[i]-'0'<0))&&a[i]!='='&&a[i]!='+'&&a[i]!='-')
            {
                float wei=0;
                x=a[i];
                a[i]='*';
                int eac=0;
                for (int l = i-1;l>=0; l--)
                { 
                    if (a[l]=='+')
                    {
                        if (eac==0)
                        {
                            eac=1;
                        }
                        if (i<eq)
                        {
                            xi=xi+eac;
                        }
                        if (i>eq)
                        {
                            xi=xi-eac;
                        }
                        break;
                    }
                    if (a[l]=='-')
                    {
                        if (eac==0)
                        {
                            eac=1;
                        }
                        if (i<eq)
                        {
                            xi=xi-eac;
                        }
                        if (i>eq)
                        {
                            xi=xi+eac;
                        }
                        break;
                    }
                    if ((a[l]-'0')<=9&&(a[l]-'0'>=0))
                    {
                        eac=eac+(a[l]-'0')*pow(10,wei);
                        a[l]='*';
                    }
                    wei++;
                    if (l==0)
                    {
                        if (eac==0)
                        {
                            eac=1;
                        }
                        xi=xi+eac;
                        break;
                    }
                    if (l==eq)
                    {
                        if (eac==0)
                        {
                            eac=1;
                        }
                        xi=xi-eac;
                        break;
                    }  
                }   
            }
        }
        if (a[eq+1]!='-'&&a[eq+1]!='*')
        {
            a[eq]='+';
        }
        int fir=-1;
        for (int i = 0;; i++)
        {
            if ((a[i]-'0')<0||(a[i]-'0')>9)
            {
                break;
            }
            if ((a[i]-'0')>=0&&(a[i]-'0')<=9)
            {
                fir=i;
            }  
        }
        if (fir!=-1)
        {
            for (int i = fir; i >= 0; i--)
            {
                c=c+(a[i]-'0')*pow(10,fir-i);
            } 
        }
        int each=0,cif=0,all=0;
        for (int i = eq-1; i > fir; i--)
        {
            if (a[i]!='*'&&a[i]!='+'&&a[i]!='-')
            {
                each=each+(a[i]-'0')*pow(10,cif);
                cif++;
            }
            if (a[i]=='+')
            {
                all=all-each;
                cif=0;
                each=0;
            }
            if (a[i]=='-')
            {
                all=all+each;
                cif=0;
                each=0;
            } 
        }
        for (int i = len-1; i >= eq; i--)
        {
            if (a[i]!='*'&&a[i]!='+'&&a[i]!='-'&&a[i]!='=')
            {
                each=each+(a[i]-'0')*pow(10,cif);
                cif++;
            }
            if (a[i]=='+')
            {
                all=all+each;
                cif=0;
                each=0;
            }
            if (a[i]=='-')
            {
                all=all-each;
                cif=0;
                each=0;
            } 
        }
        all=all-c;
        double ans=all*1.00/(xi*1.00);
        printf("%c=%.6lf\n",x,ans);
        
    }
    return 0;
}