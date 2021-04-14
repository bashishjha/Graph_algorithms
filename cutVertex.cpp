//Articulation Point 
//Cut Vertex


#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int v=5;
int t=0;
unordered_map<int,vector<int>>adj;

void solve(int u,vector<int>&dis,vector<int>&low,vector<int>&parent,vector<bool>&ap){
    dis[u]=t,low[u]=t;
    t+=1;
    int child=0;

    for(int v:adj[u]){
        if(dis[v]==-1){
            child+=1;
            parent[v]=u;
            solve(v,dis,low,parent,ap);
            low[u]=min(low[u],low[v]);

            if(parent[u]==-1&&child>1){
                ap[u]=true;
            }
            if(parent[u]!=-1&&low[v]>=dis[u]){
                ap[u]=true;
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],dis[v]);
        }      
    }


}

void findArticulate(){
    vector<int>dis(v,-1),low(v,-1),parent(v,-1);
    vector<bool>articulate_point(v,false);

    for(int i=0;i<v;++i){
        if(dis[i]==-1){
            solve(i,dis,low,parent,articulate_point);
        }
    }

    for(int i=0;i<v;++i){
        if(articulate_point[i]==true){
            cout<<i<<" ";
        }
    } 
}


int main(){
    adj[0].pb(3);
    adj[0].pb(1);
    adj[3].pb(0);
    adj[1].pb(0);
    adj[3].pb(4);
    adj[4].pb(3);
    adj[3].pb(5);
    adj[5].pb(3);
    adj[1].pb(2);
    adj[2].pb(1);
    findArticulate();
}