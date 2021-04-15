//union find algorithm for undirected graph

#include<bits/stdc++.h>
using namespace std;

int parent[1000001];

int find(int u){
    if(parent[u]==-1){
        return u;
    }
    return find(parent[u]);
}

void union1(int u,int v){
    u=find(u);
    v=find(v);
    parent[u]=v;
}

bool hasCycle(int u,int v){
    if(find(u)==find(v)){
        return true;
    }
    union1(u,v);
    return false;
}


int main(){
    memset(parent,-1,sizeof(parent));
    vector<vector<int>>edge;
    int e;
    cin>>e;
    bool res=false;
    for(int i=0;i<e;++i){
        int u,v;
        cin>>u>>v;
        res=hasCycle(u,v);
    }
    cout<<res<<endl;
    

}