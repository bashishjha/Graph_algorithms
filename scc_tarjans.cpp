#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>>adj;
int v;
int t=0;

void dfs(int u,vector<int>& dis,vector<int>& low,vector<bool>& isPresent,stack<int>& st){
    dis[u]=t;
    low[u]=t;
    t+=1;
    st.push(u);
    isPresent[u]=true;

    for(int v:adj[u]){
        if(dis[v]==-1){
            dfs(v,dis,low,isPresent,st);
            low[u]=min(low[u],low[v]);
        }
        else if(isPresent[v]){
            low[u]=min(low[u],dis[v]);
        }
    }

    if(low[u]==dis[u]){
        while (st.top()!=u){
            cout<<st.top()<<"->";
            isPresent[st.top()]=false;
            st.pop();
        }
        cout<<st.top();
        isPresent[st.top()]=false;
        st.pop();
        cout<<endl;
    }


}


void findScc(){
    vector<int>dis(v,-1),low(v,-1);
    vector<bool>isPresent(v,false);
    stack<int>st;
    for(int i=0;i<v;++i){
        if(dis[i]==-1){
            dfs(i,dis,low,isPresent,st);
        }
    }
}

main(){
    v=7;
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);
    adj[4].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(6);
    adj[5].push_back(2);
    adj[6].push_back(5);
    findScc();
}