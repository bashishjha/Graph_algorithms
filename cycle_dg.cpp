#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>>adj;
int v=3;

bool hasCycle(int u,vector<int>&vis){
    vis[u]=1;//visited node

    for(int v:adj[u]){
        if(!vis[v]){
            if(hasCycle(v,vis))//already containing cycle
                return true;
        }
        else if(vis[v]==1){//already visited 
            return true;
        }
    }
    vis[u]=2;//processed node
    return false;

}

int main(){
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    vector<int>vis(v,0);
    bool res=false;
    for(int i=0;i<v;++i){
        if(!vis[i]){
            res=hasCycle(i,vis);
        }
    }
    cout<<res<<endl;
    return 0;
}