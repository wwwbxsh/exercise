#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[1010][11];
//啊啊啊啊啊编号最小指的是仓库编号！
int ans[1010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>num[i][j];
        }
    }
    /*
    for(int i=1;i<=n;i++){
        sort(num[i]+1,num[i]+m+1);
    }
    */
    for(int i=1;i<=n;i++){
        //int ty[11]={1000001,1000001};//编号最小上级仓库
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            bool flag=1;
            for(int k=1;k<=m;k++){
                if(num[i][k]>=num[j][k]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                
                ans[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}