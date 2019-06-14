#include<bits/stdc++.h>
using namespace std;

void dfs(int s,vector<int>graph[],bool vis[])
{
	vis[s]=true;
	cout<<s<<"->";
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
		//graph[v].push_back(u); uncomment for undirected
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

/*----------------------------------------
input
10 5
1 4
4 5
7 8
9 5
4 1
output
0->
1->4->5->
2->
3->
4->5->1->
5->
6->
7->8->
8->
9->5->
*/
