#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
ll f[10000000];
void init(){
    f[0]=0;
    f[1]=1;
    for(int i=2;i<10000000;i++){
        f[i]=(f[i-1]+f[i-2])%m;//注意边mod边计算
    }
}
int main(){
    cin>>m;
    ll ans;
    init();
    for(int i=0;i<10000000;i++){
        if(f[i]==0&&f[i+1]==1&&i!=0){
            ans=i;
            break;
        }
    }
    cout<<ans;
    return 0;
}