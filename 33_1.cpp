#include<bits/stdc++.h>
using namespace std;
//n篇文章，输出1-m每个数出现在多少篇文章中，在全部文章总共出现多少次
int n,m;
int num[101][101];
int cnt[101];
int vis[101];
int sum[101];
int l[101];
int main(){
    cin>>n>>m;  
    for(int i=0;i<n;i++){
        cin>>l[i];
        for(int j=0;j<l[i];j++){
            cin>>num[i][j];
        }
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<l[i];j++){
            int now=num[i][j];
            sum[now]++;
            if(!vis[now]){
                vis[now]=1;
            }
        }
        for(int k=1;k<=m;k++){
            if(vis[k]){
                cnt[k]++;
                vis[k]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" "<<sum[i]<<"\n";
    }
    return 0;
}