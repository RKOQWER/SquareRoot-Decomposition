#include<bits/stdc++.h>
using namespace std;

void kahn(vector<int> adj[],int in[],int n);
void kahn(vector<int> adj[],int in[],int n)
{
	queue<int> q;
	int i;
	vector<int> ans;
	for(i=0;i<n;i++)
	{
		if(in[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int sz=q.size();
		while(sz--)
		{
			int f=q.front();
			ans.push_back(f);
			q.pop();
			for(int &child:adj[f])
			{
				in[child]--;
				if(in[child]==0)
				{
					q.push(child);
				}
			}
		}
	}
	if(ans.size()==n)
	{
		for(int &e:ans)
			cout<<e<<"\n";
	}
	else
		cout<<"Not a DAG\n";
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
	int in[n];
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