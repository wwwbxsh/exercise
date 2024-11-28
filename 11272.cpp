#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//快排模板题
//ea.原来是排序模板题
int n;
ll a[100001];
/*
void fastsort(int left,int right){
    int start=left;
    int end=right;
    int base=a[left];
    while(left<right){
        //先处理right
        while(left<right&&a[right]>=base){
            right--;
        }
        if(left<right)swap(a[left],a[right]);
        //再处理left
        while(left<right&&a[left]<=base){
            left++;
        }
        if(left<right)swap(a[left],a[right]);
    }
    a[left]=base;
    //迭代处理其他
    if(left-1>start)
    fastsort(start,left-1);
    if(left+1<end)
    fastsort(left+1,end);
    return;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    fastsort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
*/
//sort排序最简单
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}