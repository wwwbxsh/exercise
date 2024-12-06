#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
int n;
int k;
struct TD{
    int t;//时间
    int c;//缩短一天所需要的资源
}td[100100];
TD min(TD a,TD b){
    TD c;
    c.t=min(a.t,b.t);
    if(a.t<b.t){
        c.c=a.c;
    }
    else{
        c.c=b.c;
    }
    return c;
}
int max_day(int a,TD b){
    return max(a,b.t);
}//求最长耗时
bool check(int x){
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(td[i].t>x){
            sum+=(td[i].t-x)*td[i].c;
        }
        //此处可以剪枝
        if(sum>m){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>td[i].t>>td[i].c;
    }
    //二分
    int l=k;
    int maxx=k;
    int r;
    //k为最小，r为最大，mid也可能是r,所以r=mid
    for(int i=1;i<=n;i++){
        maxx=max_day(maxx,td[i]);
    }
    r=maxx;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<r;
    return 0;
}