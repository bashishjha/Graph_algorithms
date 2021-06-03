#include<bits/stdc++.h>
using namespace std;

void dfs(int s,vector<int>graph[],bool vis[])
{
	vis[s]=true;
	cout<<s<<" ";
	for(int i=0;i<graph[s].size();++i)
	{
		if(!vis[graph[s][i]])
			dfs(graph[s][i],graph,vis);
	}
	
}
int main()
{
	int nodes,edges;
	cin>>nodes>>edges;
	vector<int>graph[nodes];
	int u,v;
	for(int i=0;i<edges;++i)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=0;i<nodes;++i)
	{
		bool vis[nodes];
		memset(vis,false,sizeof(vis));
		dfs(i,graph,vis);
		cout<<endl;
	}
	return 0;
}

/*-------------------------------------------------------------
input 
10 5
0 1
2 4
4 8
7 9
5 6
ouput
0->1->
1->0->
2->4->8->
3->
4->2->8->
5->6->
6->5->
7->9->
8->4->2->
9->7->
*/
