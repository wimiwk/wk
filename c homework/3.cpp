#include <stdio.h>
#include <math.h>
int main() {
    int n, i;
    scanf("%d", &n); 
    for (i = 0; i < n; i++) {
        int a, b, c, d,e,f,g,h,i,j;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        g=__max(a,b),f=__max(g,c),e=__max(f,d);
        j=__min(a,b),i=__min(j,c),h=__min(i,d);
        if (h==e)
        {
            printf("%d %d %d %d\n",a,b,c,d);
        }
        if (a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
        {
            if (a==e)
            {
                if (b==h)
                {
                    if (c<d)
                {
                    printf("%d %d %d %d\n",h,c,d,e);
                }
                    if (c>d)
                {
                    printf("%d %d %d %d\n",h,d,c,e);
                }   
                }
                if (c==h)
                {
                    if (b<d)
                {
                    printf("%d %d %d %d\n",h,b,d,e);
                }
                    if (b>d)
                {
                    printf("%d %d %d %d\n",h,d,b,e);
                }   
                }
                if (d==h)
                {
                    if (b<c)
                {
                    printf("%d %d %d %d\n",h,b,c,e);
                }
                    if (b>c)
                {
                    printf("%d %d %d %d\n",h,c,b,e);
                }   
                }          
            }
            if (b==e)
            {
                if (a==h)
                {
                    if (c<d)
                {
                    printf("%d %d %d %d\n",h,c,d,e);
                }
                    if (c>d)
                {
                    printf("%d %d %d %d\n",h,d,c,e);
                }   
                }
                if (c==h)
                {
                    if (a<d)
                {
                    printf("%d %d %d %d\n",h,a,d,e);
                }
                    if (a>d)
                {
                    printf("%d %d %d %d\n",h,d,a,e);
                }   
                }
                if (d==h)
                {
                    if (c<a)
                {
                    printf("%d %d %d %d\n",h,c,a,e);
                }
                    if (c>a)
                {
                    printf("%d %d %d %d\n",h,a,c,e);
                }   
                }          
            }
            if (c==e)
            {
                if (a==h)
                {
                    if (b<d)
                {
                    printf("%d %d %d %d\n",h,b,d,e);
                }
                    if (b>d)
                {
                    printf("%d %d %d %d\n",h,d,b,e);
                }   
                }
                if (b==h)
                {
                    if (a<d)
                {
                    printf("%d %d %d %d\n",h,a,d,e);
                }
                    if (a>d)
                {
                    printf("%d %d %d %d\n",h,d,a,e);
                }   
                }
                if (d==h)
                {
                    if (b<a)
                {
                    printf("%d %d %d %d\n",h,b,a,e);
                }
                    if (b>a)
                {
                    printf("%d %d %d %d\n",h,a,b,e);
                }   
                }          
            }
            if (d==e)
            {
                if (a==h)
                {
                    if (c<b)
                {
                    printf("%d %d %d %d\n",h,c,b,e);
                }
                    if (c>b)
                {
                    printf("%d %d %d %d\n",h,b,c,e);
                }   
                }
                if (b==h)
                {
                    if (a<c)
                {
                    printf("%d %d %d %d\n",h,a,c,e);
                }
                    if (a>c)
                {
                    printf("%d %d %d %d\n",h,c,a,e);
                }   
                }
                if (c==h)
                {
                    if (b<a)
                {
                    printf("%d %d %d %d\n",h,b,a,e);
                }
                    if (b>a)
                {
                    printf("%d %d %d %d\n",h,a,b,e);
                }   
                }          
            }
        }
        if (a==b)
        {
            if (b==c&&c!=d)
            {
                if (c<d)
            {
                printf("%d %d %d %d\n",h,a,b,e);
            }
            if (c>d)
            {
                printf("%d %d %d %d\n",h,a,b,e);
            }
            }
            if (a!=c&&c==d)
            {
                if (a>c)
                {
                    printf("%d %d %d %d\n",c,d,a,b);
                }
                if (a<c)
                {
                    printf("%d %d %d %d\n",a,b,c,d);
                }
                
            }
            
            if(a!=c&&b!=d&&c!=d){
                if (a==e)
                {
                    if (c<d)
                    {
                        printf("%d %d %d %d\n",h,d,a,e);
                    }
                    if (c>d)
                    {
                        printf("%d %d %d %d\n",h,c,a,e);
                    }
                }
                if (c==e)
                {
                    if (a<d)
                    {
                        printf("%d %d %d %d\n",h,a,d,e);
                    }
                    if (a>d)
                    {
                        printf("%d %d %d %d\n",h,b,a,e);
                    }
                }
                if (d==e)
                {
                    if (a<c)
                    {
                        printf("%d %d %d %d\n",h,a,c,e);
                    }
                    if (a>c)
                    {
                        printf("%d %d %d %d\n",h,b,a,e);
                    }
                }
            }
        }
        if (a==c)
        {
            if (d==c&&c!=b)
            {
               if (b<d)
            {
                printf("%d %d %d %d\n",h,a,d,e);
            }
            if (b>d)
            {
                printf("%d %d %d %d\n",h,a,d,e);
            } 
            }
            if (b==d&&b!=c)
            {
                if (a<d)
                {
                    printf("%d %d %d %d\n",a,c,d,b);
                }
                if (a>d)
                {
                    printf("%d %d %d %d\n",d,b,a,c);
                }
                
            }
            
            if (c!=b&&c!=d&&b!=d)
            {
                if (a==e)
                {
                    if (b<d)
                    {
                        printf("%d %d %d %d\n",b,d,a,c);
                    }
                    if (b>d)
                    {
                        printf("%d %d %d %d\n",d,b,a,c);
                    } 
                }
                if (b==e)
                {
                    if (a<d)
                    {
                        printf("%d %d %d %d\n",a,c,d,b);
                    }
                    if (a>d)
                    {
                        printf("%d %d %d %d\n",d,c,a,b);
                    } 
                }
                if (d==e)
                {
                    if (a<b)
                    {
                        printf("%d %d %d %d\n",a,c,b,d);
                    }
                    if (a>b)
                    {
                        printf("%d %d %d %d\n",b,a,c,d);
                    } 
                }
            }
            
        }
        if (a==d)
        {
            if (d==b&&c!=b)
            {
                if (c<d)
            {
                printf("%d %d %d %d\n",h,a,d,e);
            }
            if (c>d)
            {
                printf("%d %d %d %d\n",h,a,d,e);
            }
            }
            if (c==b&&c!=a)
            {
                if (a<c)
                {
                    printf("%d %d %d %d\n",a,d,c,b);
                }
                if (a>c)
                {
                    printf("%d %d %d %d\n",c,b,a,d);
                }
                
            }
            
            if (a!=b&&a!=c&&c!=b)
            {
                if (a==e)
                {
                    if (b<c)
                    {
                        printf("%d %d %d %d\n",b,c,a,d);
                    }
                    if (b>c)
                    {
                        printf("%d %d %d %d\n",c,b,a,d);
                    } 
                }
                if (b==e)
                {
                    if (a<c)
                    {
                        printf("%d %d %d %d\n",a,c,d,b);
                    }
                    if (a>c)
                    {
                        printf("%d %d %d %d\n",c,a,d,b);
                    } 
                }
                if (c==e)
                {
                    if (a<b)
                    {
                        printf("%d %d %d %d\n",a,d,b,c);
                    }
                    if (a>b)
                    {
                        printf("%d %d %d %d\n",b,a,d,c);
                    } 
                }
            }
            
        }
        if (b==c)
        {
            if (d==c&&c!=a)
            {
               if (b<a)
            {
                printf("%d %d %d %d\n",h,c,d,e);
            }
            if (b>a)
            {
                printf("%d %d %d %d\n",h,c,d,e);
            } 
            }
            if (a==e)
                {
                    if (b<d)
                    {
                        printf("%d %d %d %d\n",b,c,d,a);
                    }
                    if (b>d)
                    {
                        printf("%d %d %d %d\n",d,b,c,a);
                    } 
                }
                if (b==e)
                {
                    if (a<d)
                    {
                        printf("%d %d %d %d\n",a,d,b,c);
                    }
                    if (a>d)
                    {
                        printf("%d %d %d %d\n",d,a,b,c);
                    } 
                }
                if (d==e)
                {
                    if (a<b)
                    {
                        printf("%d %d %d %d\n",a,b,c,d);
                    }
                    if (a>b)
                    {
                        printf("%d %d %d %d\n",b,c,a,d);
                    } 
                }
        }
        if (b==d)
        {
            if (a==e)
                {
                    if (b<c)
                    {
                        printf("%d %d %d %d\n",b,d,c,a);
                    }
                    if (b>c)
                    {
                        printf("%d %d %d %d\n",c,b,d,a);
                    } 
                }
                if (b==e)
                {
                    if (a<c)
                    {
                        printf("%d %d %d %d\n",a,c,b,d);
                    }
                    if (a>c)
                    {
                        printf("%d %d %d %d\n",c,a,b,d);
                    } 
                }
                if (c==e)
                {
                    if (a<b)
                    {
                        printf("%d %d %d %d\n",a,b,d,c);
                    }
                    if (a>b)
                    {
                        printf("%d %d %d %d\n",b,d,a,c);
                    } 
                }
        }
        if (c==d)
        {
            if (a=e)
                {
                    if (b<d)
                    {
                        printf("%d %d %d %d\n",b,c,d,a);
                    }
                    if (b>d)
                    {
                        printf("%d %d %d %d\n",c,b,d,a);
                    } 
                }
                if (b==e)
                {
                    if (a<d)
                    {
                        printf("%d %d %d %d\n",a,c,d,b);
                    }
                    if (a>d)
                    {
                        printf("%d %d %d %d\n",c,d,a,b);
                    } 
                }
                if (d==e)
                {
                    if (a<b)
                    {
                        printf("%d %d %d %d\n",a,b,c,d);
                    }
                    if (a>b)
                    {
                        printf("%d %d %d %d\n",b,a,c,d);
                    } 
                }
        }
    }
    return 0;
}


