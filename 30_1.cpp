#include<bits/stdc++.h>
using namespace std;
struct QP{
    string s1;
    string s2;
    string s3;
    string s4;
    string s5;
    string s6;
    string s7;
    string s8;
    bool operator ==(const QP &r)const{
        if(s1==r.s1&&s2==r.s2&&s3==r.s3&&s4==r.s4&&s5==r.s5&&s6==r.s6&&s7==r.s7&&s8==r.s8){
            return 1;
        }
        else{
            return 0;
        }
    }
}qp[110];
int ans[110];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>qp[i].s1>>qp[i].s2>>qp[i].s3>>qp[i].s4>>qp[i].s5>>qp[i].s6>>qp[i].s7>>qp[i].s8;
    }
    for(int i=0;i<n;i++){
        bool f=0;
        int cur;
        for(int j=i-1;j>=0;j--){
            if(qp[i]==qp[j]){
                f=1;
                cur=j;
                break;
            }
        }
        if(f){
            ans[i]=ans[cur]+1;
        }
        else{
            ans[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}