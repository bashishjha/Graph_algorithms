#include<bits/stdc++.h>
using namespace std;

//modified DFS
//time complexcity O(V+E)
stack<int>q;
void dfs(int source,vector<int>graph[],bool vis[])
{
	vis[source]=true;
	q.push(source);
	for(int i=0;i<graph[source].size();++i)
	{
		if(!vis[graph[source][i]])
			dfs(graph[source][i],graph,vis);
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
		//graph[v].push_back(u);
	}
	bool vis[nodes];
	memset(vis,false,sizeof(vis));
	vector<int>topsort;
	for(int i=0;i<nodes;++i)
	{
		if(!vis[i])
			dfs(i,graph,vis);
		while(!q.empty())
		{
			topsort.push_back(q.top());
			q.pop();
		}
	}
	for(int i=0;i<topsort.size();++i)
		cout<<topsort[i]<<" ";
	cout<<endl;

	return 0;
}

/*--------------------------------------------------------
input
10 13
0 1
1 7
0 5
3 2
3 4
3 8
4 8
6 0
6 1
6 2
3 7
8 2
9 4
output
5 7 1 0 2 8 4 3 6 9
*/
