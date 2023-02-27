#include<bits/stdc++.h>
using namespace std;
#define int long long
int solve(vector<pair<int,int> > adj[],int n);
int dfs(vector<pair<int,int> > adj[],int src,int sz[],
	int &ans,int n);
int dfs(vector<pair<int,int> > adj[],int src,int sz[],
	int &ans,int n)
{
	sz[src]=1;
	for(auto& child:adj[src])
	{
		int w=child.second;
		int v=child.first;
		if(sz[v]==0)
		{
			sz[src]+=dfs(adj,v,sz,ans,n);
			ans+=2*w*min(sz[v],n-sz[v]);
		}
	}
	return sz[src];
}

int solve(vector<pair<int,int> > adj[],int n)
{
	int sz[n];
	memset(sz,0,sizeof(sz));
	int ans=0;
	dfs(adj,0,sz,ans,n);
	return ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,int> > adj[n];
		for(int i=0;i<n-1;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			u--;
			v--;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		cout<<solve(adj,n)<<"\n";
	}
	return 0;
}