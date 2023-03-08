#include <stdio.h> 
#include <string.h> 
#include <math.h>   
int counter=0;
int max=100000;
void inters(int n,int k){
    if (k==0&&n==0)
    {
        counter++;
        return;
    }
    if (n==0)
    {
        return;
    }
    for (int i =__min(n,max); i > 0; i--)
    {
        max=i;
        inters(n-i,k-1);
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    inters(n,k);
    printf("%d",counter);
    return 0;
}