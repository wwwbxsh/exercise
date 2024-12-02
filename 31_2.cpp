#include<bits/stdc++.h>
using namespace std;
//重复访问序列效率过低
//前缀和减少优化，思路是缩放的累积=k乘数的累积；旋转的累计=旋转角度的相加
//1是*k,2是旋转
struct OPS{
    int num;
    double o;
}ops[100010];
struct LOc{
    double x;
    double y;
}loc[100010];
int n;
int m;
//k和angel
double k[100010];
double ang[100010];
int main(){
    cin>>n>>m;
    //memset按字节赋值，无法赋值1，可使用fill或直接k[0]=1
    //memset(k,1,sizeof(k));
    fill(k,k+10010,1);
    for(int i=1;i<=n;i++){
        cin>>ops[i].num>>ops[i].o;
    }
    //前缀和优化
    //前缀乘
    for(int i=1;i<=n;i++){
        if(ops[i].num==1){
            k[i]=k[i-1]*ops[i].o;
            ang[i]=ang[i-1];
        }
        else if(ops[i].num==2){
            ang[i]=ang[i-1]+ops[i].o;
            k[i]=k[i-1];
        }
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r>>loc[i].x>>loc[i].y;
        double k1=k[r]/k[l-1];
        loc[i].x=loc[i].x*(k1);
        loc[i].y=loc[i].y*(k1);
        double x=loc[i].x;
        double y=loc[i].y;
        loc[i].x=x*cos(ang[r]-ang[l-1])-y*sin(ang[r]-ang[l-1]);
        loc[i].y=x*sin(ang[r]-ang[l-1])+y*cos(ang[r]-ang[l-1]);
        /*
        for(int j=l;j<=r;j++){
            
            if(ops[j].num==1){
                loc[i].x*=ops[j].o;
                loc[i].y*=ops[j].o;
            }
            else if(ops[j].num==2){
                //aaaaaaaaaaaloc[i].x变了TTfoolish·error
                double x=loc[i].x;
                double y=loc[i].y;
                loc[i].x=x*cos(ops[j].o)-y*sin(ops[j].o);
                loc[i].y=x*sin(ops[j].o)+y*cos(ops[j].o);
            }
            
        }
        */
    }
    for(int i=0;i<m;i++){
        printf("%lf %lf\n",loc[i].x,loc[i].y);
    }
    return 0;
}