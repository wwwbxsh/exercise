#include<bits/stdc++.h>
using namespace std;
double zc;//支出
double sr;//收入
int main(){
    int n;
    double lx;
    cin>>n>>lx;
    //转化为当前价值
    //注意细节！
    for(int i=0;i<=n;i++){
        int w;
        cin>>w;
        if(w<0){
            zc+=w*pow((1+lx),-i);
        }
        else{
            sr+=w*pow((1+lx),-i);
        }
    }
    cout<<sr+zc;
    return 0;
}