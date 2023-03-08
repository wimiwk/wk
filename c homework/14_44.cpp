#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    getchar();
    int hex_to_dex(char a[]); 
    for(int i=0;i<n;i++){
            char gyx[200]={};
            fgets(gyx,200,stdin);
        
            for(int i1=0;i1<strlen(gyx)-1;i1+=2){
       
                int g=hex_to_dex(&gyx[i1]);
                printf("%c",g);
            }
            cout<<endl;
    }
}
int hex_to_dex(char a[]){
    char a1=a[0];
    char a2=a[1];
    if(a1>57){
        a1=a1-'A'+10;
    }
    else a1=a1-'0';
     if(a2>57){
        a2=a2-'A'+10;
    }
    else a2=a2-'0';
    return (a1*16+a2);
}