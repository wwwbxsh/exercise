#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll m;
struct Ops{
    ll dx;
    ll dy;
}ops[110];//操作系列
struct Loc{
    ll x;
    ll y;
}loc[110];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>ops[i].dx>>ops[i].dy;
    }
    for(int i=0;i<m;i++){
        cin>>loc[i].x>>loc[i].y;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            loc[i].x+=ops[j].dx;
            loc[i].y+=ops[j].dy;
        }
    }
    for(int i=0;i<m;i++){
        cout<<loc[i].x<<" "<<loc[i].y<<"\n";
    }
    return 0;
}