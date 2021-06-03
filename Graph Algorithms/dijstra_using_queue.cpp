#include<bits/stdc++.h>
using namespace std;

void djs(vector<vector<int> >graph,int src,int v)
{
	queue<int>q;
	q.push(src);
	vector<int>dist(v,INT_MAX);
	dist[src]=0;
	while(!q.empty())
	{
		int front=q.front();
		q.pop();
		for(int i=0;i<v;++i)
		{
			if(dist[i]>dist[front]+graph[front][i])
			{
				dist[i]=min(dist[i],dist[front]+graph[front][i]);
				q.push(i);
			}
		}
	}
	for(int i=0;i<v;++i)
		cout<<dist[i]<<" ";
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int v;
		cin>>v;
		vector<vector<int> >graph(v);
		for(int i=0;i<v;++i)
		{
			vector<int>temp(v);
			graph[i]=temp;
		}
		for(int i=0;i<v;++i)
			for(int j=0;j<v;++j)
				cin>>graph[i][j];
		int src;
		cin>>src;
		djs(graph,src,v);
	}
	return 0;
}

/*--------------------------------------------------------------------
input:-
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2
output:-
0 25
7 6 0 */
