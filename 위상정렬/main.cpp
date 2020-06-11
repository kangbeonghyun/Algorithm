

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int n,m;
int degree[32001];
vector<int> v[32001];


void search(){
    
    priority_queue<int,vector<int>,greater<int>> que;
    
    for(int i=1;i<=n;++i){
        if(degree[i]==0)que.push(i);
    }
        
    while(!que.empty()){
        int a=que.top();
        que.pop();
        cout<<a<<" ";
        
        for(int i=0;i<v[a].size();++i){
            if(degree[v[a][i]]==1){
                que.push(v[a][i]);
                
            }
            degree[v[a][i]]--;
            
        }
        
        
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>n>>m;
    
    for(int i=0;i<m;++i){
        int pre,after;
        cin>>pre>>after;
        v[pre].push_back(after);
        degree[after]++;
    }
    
    search();
    return 0;
}
