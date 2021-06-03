#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<pair<int,int>>>adj;
int v=5;

void solve(int src){
    vector<int>dis(v,INT_MAX);
    set<pair<int,int>>s;
    s.insert({0,src});
    dis[src]=0;
    while(!s.empty()){
        auto cur=*(s.begin());
        s.erase(s.begin());
        int u=cur.second;
        for(auto i:adj[u]){
            if(dis[i.first]>dis[u]+i.second){
                    if(dis[i.first]!=INT_MAX){
                        s.erase({dis[i.first],i.first});
                    dis[i.first]=dis[u]+i.second;
                    s.insert({dis[i.first],i.first});
                }
            }
        }
    }
}


int main(){
    int src;
    cin>>src;
    solve(src);
}