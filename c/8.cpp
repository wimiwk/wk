#include <stdio.h>
int main (){
	int i=1,j=2,k;
    k=i>j?i:j;//i>j如果为1，则选第二个i；如果为0，则选第三个j
    //可用作if
    k=1?2:3;
    printf("%d",k);
	return 0;
}