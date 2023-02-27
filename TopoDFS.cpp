/*
 Topological sort is valid for only DAG.
 Toposort output is not unique.
 Topological sorting for Directed Acyclic Graph (DAG) is a
 linear ordering of vertices such that for every directed
 edge u v, vertex u comes before v in the ordering.

*/
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],int src,bool vis[],stack<int> &st);
void dfs(vector<int> adj[],int src,bool vis[],stack<int> &st)
{
	vis[src]=true;
	for(int &child:adj[src])
	{
		if(!vis[child])
			dfs(adj,child,vis,st);
	}
	st.push(src);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,e;
	cin>>n>>e;
	vector<int> adj[n];
	int i;
	for(i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	bool vis[n];
	memset(vis,0,sizeof(vis));
	stack<int> st;
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(adj,i,vis,st);
		}
	}
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}