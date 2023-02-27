#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int parent[N];

void make(int v)
{
	parent[v]=v;
}

int find(int v)
{
	if(v==parent[v])
		return v;
	else
		parent[v]=find(parent[v]);
}

void Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
	{
		parent[a]=max(parent[a],parent[b]);
		parent[b]=parent[a];
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
	int l[e],r[e],c[e];
	int i;
	for(i=0;i<e;i++)
		cin>>l[i]>>r[i]>>c[i];
	vector<int> res(n+2,0);
	for(i=e-1;i>=0;i--)
	{
		int index=find(l[i]);
		while(index<=r[i])
		{
			res[index]=c[i];
			Union(index,index+1);
			index=find(index);
		}
	}
	for(i=1;i<=n;i++)
		cout<<res[i]<<"\n";
	return 0;
}