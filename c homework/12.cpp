#include <stdio.h>
int main() {
   int n,c;
   scanf("%d",&n);
   int a[n+10];
   for (int i = 0; i < n; i++)
   {
    scanf("%d",&a[i]);
   }
   for (int l = 0; l < n-1; l++)
   {
   for (int i = 0; i < n-1; i++)
   {
    if (a[i]>=a[i+1])
    {
        c=a[i];
        a[i]=a[i+1];
        a[i+1]=c;
    }
   }
   for (int f = 0; f < n; f++)
   {
    printf("%d ",a[f]);
   }
   printf("\n");
   }
  return 0;
}