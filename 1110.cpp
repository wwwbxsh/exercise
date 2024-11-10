#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//TLE
//记忆化搜索******
ll dp[30][30][30];
bool vis[30][30][30];
int w(ll a,ll b,ll c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }
    else if(a>20||b>20||c>20){
        if(!vis[20][20][20])
        dp[20][20][20]=w(20,20,20);
        vis[20][20][20]=1;
        return dp[20][20][20];
    }
    else if((a<b)&&(b<c)){
        if(!vis[a][b][c-1]){
            dp[a][b][c-1]=w(a,b,c-1);
            vis[a][b][c-1]=1;
        }
        if(!vis[a][b-1][c-1]){
            dp[a][b-1][c-1]=w(a,b-1,c-1);
            vis[a][b-1][c-1]=1;
        }
        if(!vis[a][b-1][c]){
            dp[a][b-1][c]=w(a,b-1,c);
            vis[a][b-1][c]=1;
        }
        dp[a][b][c]=dp[a][b][c-1]+dp[a][b-1][c-1]-dp[a][b-1][c];
    }
    else{
        if(!vis[a-1][b][c]){
            dp[a-1][b][c]=w(a-1,b,c);
            vis[a-1][b][c]=1;
        }
        if(!vis[a-1][b-1][c]){
            dp[a-1][b-1][c]=w(a-1,b-1,c);
            vis[a-1][b-1][c]=1;
        }
        if(!vis[a-1][b][c-1]){
            dp[a-1][b][c-1]=w(a-1,b,c-1);
            vis[a-1][b][c-1]=1;
        }
        if(!vis[a-1][b-1][c-1]){
            dp[a-1][b-1][c-1]=w(a-1,b-1,c-1);
            vis[a-1][b-1][c-1]=1;
        }
        dp[a][b][c]=dp[a-1][b][c]+dp[a-1][b-1][c]+dp[a-1][b][c-1]-dp[a-1][b-1][c-1];
    }
    vis[a][b][c]=1;
    return dp[a][b][c];
}
ll ans;
int main(){
    ll a,b,c;
    while(cin>>a>>b>>c){
        if(a==-1&&b==-1&&c==-1){
            break;
        }
        ans=w(a,b,c);
        //光是格式这就有四个空格...
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,ans);
    }
    return 0;
}