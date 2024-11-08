#include<bits/stdc++.h>
using namespace std;
//应该是递推而不是递归
//f[1]=f[0]=1.f[2]=f[3]=2,f[4]=f[5]=4
//0
//1
//2 2;1
//3 3;1
//4 4;2 4;1 4;2;1
//6 6;3 6;2 6;1 6;3;1 6;2;1
//n%2==1,f[n]=f[n-1]
//n%2==0,f[n]=f[n/2]+f[n-1]
int f[1001];
int main(){
    int n;
    cin>>n;
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++){
        if(i%2==1){
            f[i]=f[i-1];
        }
        else{
            f[i]=f[i/2]+f[i-1];
        }
    }
    cout<<f[n];
    return 0;
}