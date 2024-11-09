#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//判断是否为质数
long long int num[21];
ll ans=0;
int cnt=0;
int n,k;
long long int sum;
bool judge(ll sum){
    if(sum==1||sum==2){
        return 1;
    }
    for(int i=2;i<sum;i++){
        if(sum%i==0)
        return 0;
    }
    return 1;
}
void dfs1(int u){
    if(u==n)
    return;
    cnt++;
    sum+=num[u];
    if (cnt == k)
    {
        if(judge(sum))
        ans++;
        return;
    }
    for(int i=u+1;i<n;i++){
        dfs1(i);
        cnt--;
        sum-=num[i];//恢复原状态
    }
    return;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<=n+1-3;i++){
        cnt=0;
        sum=0;//初始化
        dfs1(i);
    }
    cout<<ans;
    return 0;
}