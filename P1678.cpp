#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
ll n;
ll stu[100010];//学生估分
ll sto[100010];//学校分数
ll sum;
bool check(ll x,ll stu){
   if(x>stu){
    return true;
   }
   else 
   return false;
}
int main(){
    //尝试用二分-有序序列！
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>sto[i];
    }
    for(int i=0;i<n;i++){
        cin>>stu[i];
    }
    //从小到大排序
    sort(sto,sto+m);
    //l,r应该为区间的索引，因为这些数值是固定的
    //sto[mid]>stu[i]学校分数大于估分,向左找，mid可能是合理的,r=mid
    for(int i=0;i<n;i++){
        ll l=0;
        ll r=m-1;
        //整数版的区间，相当于误差为一，所以else更改
        while(l+1<r){
            int mid=l+r+1>>1;
            if(check(sto[mid],stu[i]))r=mid;
            else l=mid;
        }
        sum+=min(abs(stu[i]-sto[r]),abs(stu[i]-sto[l]));
    }
    cout<<sum;
    return 0;
}