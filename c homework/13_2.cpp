#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int a1[3],a2[3],r1,r2,b[3],c1,c2;
        scanf("%d%d%d%d%d%d%d%d%d%d%d",&a1[0],&a1[1],&a1[2],&r1,&a2[0],&a2[1],&a2[2],&r2,&b[0],&b[1],&b[2]);
        int loj1=pow(r1,2)-(pow((b[0]-a1[0]),2)+pow((b[1]-a1[1]),2)+pow((b[2]-a1[2]),2));
        int loj2=pow(r2,2)-(pow((b[0]-a2[0]),2)+pow((b[1]-a2[1]),2)+pow((b[2]-a2[2]),2));
        if (loj1==loj2) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}