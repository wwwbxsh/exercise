#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int main(){
    int x0=0,y0=0;
    cin>>n>>x0>>y0;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a>=0&&b>=0&&c<=x0&&d<=y0){
            ans+=(c-a)*(d-b);
        }//田地完全在区域内
        else if((a>=x0)||(d<=0)||(c<=0)||(b>=y0)){
            continue;
        }//田地完全不在，右/下/左/上
        else{
            ans+=(min(c,x0)-max(a,0))*(min(d,y0)-max(b,0));
            /*
            if(a<x0&&b<y0&&c>x0&&d>y0){
                ans+=(x0-a)*(y0-b);
            }//左下在区域内
            else if(a<x0&&d>0&&b<0&&c>x0){
                ans+=(x0-a)*d;
            }
            //左上
            else if(c<x0&&d<y0&&a<0&&b<0){
                ans+=c*d;
            }
            //右上
            else if(a<0&&b>0&&c<x0&&d<y0){
                ans+=c*(y0-d);
            }
            //右下
            else if(a>=0&&c<=x0){
                ans+=(c-a)*(min(d,y0)-max(0,b));
            }//上下边出边界
            else if(b>=0&&d<=y0){
                ans+=(d-b)*(min(c,y0)-max(a,0));
            }//左右边出界
            */
        }//部分在
    }
    cout<<ans;
    return 0;
}