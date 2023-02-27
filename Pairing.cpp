#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
#define ll long long
int sz[N];
int parent[N];

void make(int v);
int find(int v);
void Union(int a,int b);

void make(int v)
{
	sz[v]=1;
	parent[v]=v;
}

int find(int v)
{
	if(v==parent[v])
		return v;
	else
		return parent[v]=find(parent[v]);
}

void Union(int a,int b)
{
	a=find(a);
	b=find(b);

	if(a!=b)
	{
		if(sz[a]>sz[b])
		{
			sz[a]+=sz[b];
			parent[b]=a;
		}
		else
		{
			sz[b]+=sz[a];
			parent[a]=b;
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
	int i;
	for(i=0;i<n;i++)
		make(i);
	for(i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		Union(u,v);
	}
	ll c=1ll*n*(n-1);
	c/=2;
	for(i=0;i<n;i++)
	{
		if(parent[i]==i)
		{
			c-=(sz[i]*(sz[i]-1))/2;
		}
	}
	cout<<c<<"\n";
	return 0;
}