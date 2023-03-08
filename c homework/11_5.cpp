#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        char a[1020],b[520],d[520];
        int c[520]={0},e[520],wk=0,ajin=0,air=0;
        scanf("%s %s",a,b);
        int lena=strlen(a),lenb=strlen(b),lena2=strlen(a);
        d[0]='0';
        for (int i = 0; i < lenb; i++)
        {
            d[i+1]=b[i];
        }
        for (int i = 0; i <= lena2-lenb; i++)
        {
            int count=0;
            int wimi=0;
            for (int l = 0; l < lenb; l++)
            {
                if (a[l]<b[l])
                {
                    if (a[l]=='0')
                    {
                        c[i]=0;
                        wimi=1;
                        break;
                    }
                    else{
                    wimi=1;
                    wk=1;
                    if (!air)
                    {
                        c[i]=0;
                        i++;
                    }
                    else air=0;
                    break;
                    }
                }
                else if (a[l]==b[l]&&l==lenb-1)
                {
                    c[i]=1;
                    ajin=l;
                    break;
                }
                else if (a[l]>b[l]){
                    break;
                }
            }
            int h=1;
            if (!wimi&&c[i]!=1)
            {
                int jin=0;
                for (int l = 0; h==1 ; l++)
                {
                    for (int ll = lenb-1; ll >= 0; ll--)
                    {
                        if ((a[ll]-'0'-jin)>=(b[ll]-'0'))
                        {
                            a[ll]=(a[ll]-'0')-(b[ll]-'0')-jin+'0';
                            jin=0;
                        }
                        else{
                            a[ll]=(a[ll]-'0')+10-(b[ll]-'0')-jin+'0';
                            jin=1;
                        }
                    }
                    count++;
                    for (int i = 0; i < lenb; i++)
                    {
                        if (a[i]<b[i])
                        {
                            h=0;
                            break;
                        }
                        else if (a[i]>b[i])
                        {
                            break;
                        }
                    }
                }
                c[i]=count;
                if (a[0]!='0')
                {
                    air=1;
                }
                
            }
            if (wk)
            {
                int jin=0;
                for (int l = 0; h==1 ; l++)
                {
                    for (int ll = lenb; ll >= 0; ll--)
                    {
                        if ((a[ll]-'0'-jin)>=(d[ll]-'0'))
                        {
                            a[ll]=(a[ll]-'0')-(d[ll]-'0')-jin+'0';
                            jin=0;
                        }
                        else{
                            a[ll]=(a[ll]-'0')+10-(d[ll]-'0')-jin+'0';
                            jin=1;
                        }
                    }
                    count++;
                    for (int i = 0; i <= lenb; i++)
                    {
                        if (a[i]<d[i])
                        {
                            h=0;
                            break;
                        }
                        if (a[i]>d[i])
                        {
                            break;
                        }
                        else if (a[i]==d[i]&&i==lenb){
                            h=0;
                            count++;
                            break;
                        }
                    }
                }
                c[i]=count;
                wk=0;
                for (int i = 0; i < lenb; i++)
                {
                for (int i = 0; i < lena-1; i++)
                {
                    a[i]=a[i+1];
                }
                }
                if (a[0]!='0')
                {
                    air=1;
                }
            }
            if (!air)
            {
            for (int i = 0; i < lena-1; i++)
            {
                a[i]=a[i+1]; 
            }
            a[lena-1]=0;
            lena--;
            }
            if (ajin)
            {
                lena=lena-ajin;
                ajin=0;
            }  
        }
        int opp=0;
        for (int i = 0;i <= lena2-lenb; i++)
        {
            if (opp!=0||c[i]!=0)
            {
                printf("%d",c[i]);
                opp++;
            }
        }
        printf("\n");  
    }   
    return 0;
}