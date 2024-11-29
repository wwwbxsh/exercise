#include<bits/stdc++.h>
using namespace std;
//字符串处理。。。不区分大小写的字符串比较
//快速去重
//STL：：set容器，不允许值重复=键值一体的map
//set基本用法https://blog.csdn.net/yas12345678/article/details/52601454
//transform(s1[i].begin(),s1[i].end(),s1[i].begin(),::tolower);
//或直接使用ASCII码，+'A'-'a'
int n,m;
string s;
set<string>s1;
set<string> s2;
int jj;//交集
int bj;//并集
void trans(){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z')
        continue;
        else
        s[i]=s[i]+'A'-'a';//全部转换为大写
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        //transform(s.begin(),s.end(),s.begin(),::tolower);//转换为小写

        trans();
        s1.insert(s);
    }
    for(int i=0;i<m;i++){
        cin>>s;
        //transform(s.begin(),s.end(),s.begin(),::tolower);
        
        trans();
        s2.insert(s);
    }
    /*
    for(auto &i:s1){
        cout<<i<<" ";
    }
    */
    //set遍历方法
    for(auto i=s1.begin();i!=s1.end();i++){
        if(s2.find(*i)!=s2.end()){
            jj++;
        }//找到了交集
    }
    /*
    for(const auto&item:s1){
        cout<<item;
    }
    */
    cout<<jj<<"\n"<<s1.size()+s2.size()-jj;
    return 0;
}