#include<bits/stdc++.h>
using namespace std;
int n,m;
struct KM{
    int bef;//依赖关系的编号
    vector<int> back;
    int day;//所需时间
}km[110];
int first[110];
int endd[110];
int degree[110];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>km[i].bef;
        if(km[i].bef!=0){
            int h=km[i].bef;
            km[h].back.push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        cin>>km[i].day;
    }
    //拓扑序
    //计算入度
    for(int i=1;i<=m;i++){
        if(km[i].bef==0){
            degree[i]=0;
        }
        if(!km[i].back.empty()){
            for(auto &it:km[i].back){
                degree[it]++;
            }
        }
    }
    //生成拓扑序列
    queue<int> q;
    //初始化度数为0的端点
    for(int i=1;i<=m;i++){
        if(degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        int bef=km[now].bef;
        for(auto &j:km[now].back){
            if(--degree[j]==0){
                q.push(j);
            }
        }
        //最早/晚开始时间
        //最晚开始时间应该从后面开始计算
        if(bef==0){
            first[now]=1;
            //endd[now]=n-km[now].day+1;
        }
        else{
            first[now]=first[bef]+km[bef].day;
            //就这么轻轻把endd写成first
            //endd[now]=n-endd[bef]-km[now].day;
        }    
    }
    //最晚时间在拓扑排序后进行
     for (int i = 1; i <= m; i++) {
        if (km[i].back.empty()) {
            // 对于没有后继节点的任务，最晚结束时间是n - 所需时间 + 1
            endd[i] = n - km[i].day + 1;
        }
    }

    // 从最后一个任务开始处理，逆向更新最晚结束时间
    for (int i = m; i >= 1; i--) {
        // 处理有后继的任务
        if (!km[i].back.empty()) {
            int min_end_time = n; // 初始化为最大时间
            // 查找所有后继任务的最晚开始时间
            for (auto &j : km[i].back) {
                min_end_time = min(min_end_time, endd[j]);
            }
            // 当前任务的最晚结束时间是最晚开始时间减去当前任务的时间
            endd[i] = min_end_time - km[i].day;
        }
    }
    /*
    //计算最晚最早开始时间,+day>n则无法完成
    int maxx=-1;
    for(int i=1;i<=m;i++){
        if(first[i]+km[i].day>maxx){
            maxx=first[i]+km[i].day;
        }
    }
    //不应该只是最晚完成时间，而是最晚完成时间和完成时间的相加
    if(maxx>n){
        for(int i=1;i<=m;i++){
            cout<<first[i]<<" ";
        }
    }
    else{
        for(int i=1;i<=m;i++){
            cout<<first[i]<<" ";
        }
        cout<<"\n";
        for(int i=1;i<=m;i++){
            cout<<endd[i]<<" ";
        }
    }
    */
    // 检查是否所有任务都能在 n 天内完成
    //应该为全局性检查
    bool f= true;
    for (int i = 1; i <= m; i++) {
        if (endd[i] >n||endd[i]<=0) {
            f = false;
            break;
        }
    }

    // 输出最早开始时间
    for (int i = 1; i <= m; i++) {
        cout << first[i] << " ";
    }
    cout << "\n";

    // 如果可以按时完成，则输出最晚结束时间
    if (f) {
        for (int i = 1; i <= m; i++) {
            cout << endd[i] << " ";
        }
    }

    return 0;
}