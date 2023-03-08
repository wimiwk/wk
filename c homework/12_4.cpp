#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
int main() { 
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        char b[900];
        scanf("%s",b);
        int lenb=strlen(b);
        if (b[0]=='-')
        {
            printf("负");
            for (int i = 0; i < lenb-1; i++)
            {
                b[i]=b[i+1];
            }
            lenb--;
        }
        for (int i = 0; i < lenb; i++)
        {
            switch (b[i])
            {
            case '1':printf("壹");break;
            case '2':printf("贰");break;
            case '3':printf("叁");break;
            case '4':printf("肆");break;
            case '5':printf("伍");break;
            case '6':printf("陆");break;
            case '7':printf("柒");break;
            case '8':printf("捌");break;
            case '9':printf("玖");break;
            default:break;           
            }
            if (b[i]=='0'&&i!=lenb-1&&b[i+1]!='0')
            {
                printf("零");
            }
            if (b[i]!='0')
            {
            switch (lenb-i)
            {
            case 8:printf("仟");break;
            case 4:printf("仟");break;
            case 7:printf("佰");break;
            case 3:printf("佰");break;
            case 6:printf("拾");break;
            case 2:printf("拾");break;           
            default:break;
            }
            }
            if (lenb-i==5)
            {
                printf("万");
            }
        }
        if (lenb==1&&b[0]=='0')
        {
            printf("零");
        }
        
        printf("圆");
        printf("\n");
    }     
    return 0;
    }