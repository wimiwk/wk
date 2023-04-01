#include<bits/stdc++.h> 
using namespace std;
const int N=16;
int stone[N][5];
int score[5];
vector<int>result;
int n;
void solution(int index){
    bool flag=true;
    for(int i=0;i<5;i++){
        if(score[i]!=0) flag=false;
        if(score[i]<0) return;
    }
    if(flag){
        for(int i=0;i<result.size();i++){
            printf("%d ",result[i]);
        }
        exit(0);
    } 
    for(int i=index;i<n;i++){
        for(int j=0;j<5;j++){
            score[j]-=stone[i][j];
        }
        result.push_back(i+1);
        solution(i+1);
        for(int j=0;j<5;j++){
            score[j]+=stone[i][j];
        }
        result.pop_back();
    }
}
int main( )
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&stone[i][j]);
        }
    }
    for(int i=0;i<5;i++){
        scanf("%d",&score[i]);
    }
    solution(0);
    return 0;
}