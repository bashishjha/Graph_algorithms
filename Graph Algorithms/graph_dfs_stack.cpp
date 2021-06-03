#include<bits/stdc++.h>
using namespace std;

void dfs(int source,vector<int>graph[],bool vis[])
{
	vis[source]=true;
	stack<int>q;
	q.push(source);
	while(!q.empty())
	{
		int t=q.top();
			cout<<t<<"->";
		q.pop();
		for(int i=0;i<graph[t].size();++i)
		{
			if(!vis[graph[t][i]])
			{
				vis[graph[t][i]]=true;
				q.push(graph[t][i]);
			}
		}
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
		graph[v].push_back(u);//comment this for directed
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

/*---------------------------------------------
input
5 4
0 1
0 2
0 3
2 4
output
0->3->2->4->1->
1->0->3->2->4->
2->4->0->3->1->
3->0->2->4->1->
4->2->0->3->1->*/
