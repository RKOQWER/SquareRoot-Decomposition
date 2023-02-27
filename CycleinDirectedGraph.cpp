/*
 status=-1 unvisited
 status=0 visited and in current path
 status=2 visited and not in current path

*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[],int status[],int src);
bool dfs(vector<int> adj[],int status[],int src)
{
	status[src]=1;
	for(int &child:adj[src])
	{
		if(status[child]==-1)
		{
			bool f=dfs(adj,status,child);
			if(f)
				return true;
		}
		else if(status[child]==0)
			return true;
		else
			continue;
	}
	status[src]=2;
	return false;
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
	int i;
	vector<int> adj[n];
	for(i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
	}
	int status[n];
	memset(status,-1,sizeof(status));
	for(i=0;i<n;i++)
	{
		bool f=dfs(adj,status,i);
		if(f)
		{
			cout<<"Cycle present\n";
			return 0;
		}
	}
	cout<<"Cycle not present\n";
	return 0;
}