#include<bits/stdc++.h>
using namespace std;
int n,k;
long long dp[100001];
//递推不可行，尝试记忆化搜索
long long dfs(int leave){
    
    if(leave<0){
        return 0;
    }//爬多，不成立
    if(leave==0){
        return 1;
    }//正好爬完台阶,方案数加1
    //先看leave是否越界
    if(dp[leave]!=-1){
        return dp[leave];
    }
    long long ans=0;
    for(int i=1;i<=k;i++){
        //爬i阶
        ans+=dfs(leave-i);
        ans%=100003;//提前取余
    }
    dp[leave]=ans;
    return dp[leave];
}//每次有k种选择
int main(){
    //数组初始化
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    cout<<dfs(n);//leave还剩多少级台阶
    return 0;
}