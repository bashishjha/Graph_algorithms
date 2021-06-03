#include<bits/stdc++.h>
using namespace std;
//O(V+E)
stack<int>q;

void dfs(int s,vector<int>g[],bool vis[])
{
	vis[s]=true;
	//cout<<s<<" ";
	q.push(s);
	for(int i=0;i<g[s].size();++i)
	{
		if(!vis[g[s][i]])
			dfs(g[s][i],g,vis);
	}
}

void dfs1(int s,vector<int>g[],bool vis[])
{
	vis[s]=true;
	cout<<s<<" ";
	//q.push(s);
	for(int i=0;i<g[s].size();++i)
	{
		if(!vis[g[s][i]])
			dfs1(g[s][i],g,vis);
	}
}
int main()
{
	int n,e;
	cin>>n>>e;
	vector<int> g[n];
	vector<int> gt[n];
	for(int i=0;i<e;++i)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		gt[v].push_back(u);
	}
	vector<int>topsort;
	bool vis[n];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;++i)
	{
		if(!vis[i])
		dfs(i,g,vis);
		while(!q.empty())
		{
			topsort.push_back(q.top());
			q.pop();
		}
	}
	reverse(topsort.begin(),topsort.end());
	bool vis1[n];
	memset(vis1,false,sizeof(vis1));
	for(int i=0;i<topsort.size();++i)
	{
		if(!vis1[topsort[i]])
		{
			dfs1(topsort[i],gt,vis1);
			cout<<endl;
		}
	}
}

/*--------------------------------------------
input
9 10
0 1
1 2
2 3
2 4
3 0
4 5
5 6
6 4
7 6
7 8
output
7
8
0 3 2 1
4 6 5
*/
