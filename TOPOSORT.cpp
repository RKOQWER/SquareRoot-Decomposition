#include<bits/stdc++.h>
using namespace std;

void kahn(vector<int> adj[],int in[],int n);
void kahn(vector<int> adj[],int in[],int n)
{
	priority_queue<int,vector<int>,greater<int> > pq;
	int i;
	vector<int> ans;
	for(i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			pq.push(i);
		}
	}
	while(!pq.empty())
	{
		int f=pq.top();
		pq.pop();
		ans.push_back(f);
		for(int &child:adj[f])
		{
			in[child]--;
			if(in[child]==0)
				pq.push(child);
		}
	}
	if(ans.size()==n)
	{
		for(int &e:ans)
			cout<<e<<" ";
		cout<<"\n";
	}
	else
		cout<<"Sandro fails.\n";
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
	// 1 based indexing
	vector<int> adj[n+1];
	int i;
	int in[n+1];
	memset(in,0,sizeof(in));
	for(i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		in[v]++;
	}
	kahn(adj,in,n);
	return 0;
}