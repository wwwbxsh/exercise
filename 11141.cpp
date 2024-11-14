#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
int main(){
    int a1,a2;
    cin>>a1>>a2>>n;
    int d=a2-a1;
    ans=a1;
    long long be=a1;
    for(int i=1;i<n;i++){
        be+=d;
        ans+=be;
    }
    cout<<ans;
    return 0;
}