#include<bits/stdc++.h>
using namespace std;
//不想做模拟。
int n;//毯子数量
struct TZ{
    int x1,y1;//左下
    int x2,y2;//右下
    int x3,y3;//右上
    int x4,y4;//左上
    bool in(int x,int y){
        if(x>=x1&&x<=x3&&y>=y1&&y<=y3)
        return 1;
        else
        return 0;
    }
};
int main(){
    cin>>n;
    TZ tz[n+1];
    for(int i=1;i<=n;i++){
        int a,b,c,g;//左下角，x，y
        cin>>a>>b>>c>>g;
        tz[i].x1=a;
        tz[i].y1=b;
        tz[i].x2=a+c;
        tz[i].y2=b;
        tz[i].x3=a+c;
        tz[i].y3=b+g;
        tz[i].x4=a;
        tz[i].y4=b+g;
    }//初始化
    int x,y;
    cin>>x>>y;
    int ans=-1;
    for(int i=1;i<=n;i++){
        if(tz[i].in(x,y)){
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}