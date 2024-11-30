#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//质数的分解：首要思路是将数分到不能再分
//易超时，质因数分解模板可记
//T2基本仍需要遍历
ll n;
ll k;
ll ans;
void divide(){
    ans=1;
    int cnt;
    bool f=0;
    //如果一个数 n 有一个大于 sqrt(n) 的因数，那么它一定还有一个小于 sqrt(n) 的因数。换句话说，所有大于 sqrt(n) 的因数都会在之前的检查中已经被考虑过了。
    //减少重复计算
    for(int i=2;i<=sqrt(n);i++){
        cnt=0;
        f=0;
        while(n%i==0){
            cnt++;
            n=n/i;
            f=1;
        }
        if(f==1&&cnt>=k){
            ans=ans*pow(i,cnt);
        }
    }
}
int main(){
    int q;
    cin>>q;
    for(ll i=0;i<q;i++){
        cin>>n>>k;
        divide();
        cout<<ans<<"\n";
    }
    return 0;
}