#include<bits/stdc++.h>
using namespace std;
//顺序取数避免重复性问题
int n,k;
int ans;
void dfs(int last,int s,int cur){
    if(cur==0){
        if(s==0){
        ans++;
        }//满足条件
        return;
    }
    for(int i=last;i<=s/cur;i++){
        dfs(i,s-i,cur-1);
    }
    return;
}//上一个数，剩余数，次数
int main(){
    cin>>n>>k;
    dfs(1,n,k);
    cout<<ans;
    return 0;
}