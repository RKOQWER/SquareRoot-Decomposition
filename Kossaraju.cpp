#include<bits/stdc++.h>
using namespace std;

void dfs1(vector<int> adj[],bool vis[],int src,stack<int>&st);
void dfs(vector<int> g[],bool vis[],int src);
void dfs1(vector<int> adj[],bool vis[],int src,stack<int>&st)
{
	vis[src]=true;
	for(int &child:adj[src])
	{
		if(!vis[child])
		{
			dfs1(adj,vis,child,st);
		}
	}
	st.push(src);
}

void dfs(vector<int> g[],bool vis[],int src)
{
	vis[src]=true;
	for(int &child:g[src])
	{
		if(!vis[child])
		{
			dfs(g,vis,child);
		}
	}
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
	vector<int> g[n];
	int i;
	for(i=0;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		g[v].push_back(u);
	}
	stack<int> st;
	bool vis[n];
	int cc=0;
	memset(vis,0,sizeof(vis));
	for(i=0;i<n;i++)
	{
		if(!vis[i])
			dfs1(adj,vis,i,st);
	}
	memset(vis,0,sizeof(vis));
	while(!st.empty())
	{
		int f=st.top();
		st.pop();
		if(!vis[f])
		{
			cc++;
			dfs(g,vis,f);
		}
	}
	cout<<cc<<"\n";
	return 0;
}