#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<string> &grid,int m,int n);

void dfs(vector<string> &grid,vector<vector<bool> >&vis,
	int i,int j,int m,int n);
void dfs(vector<string> &grid,vector<vector<bool> >&vis,
	int i,int j,int m,int n)
{
	if(i<0 || i>=m || j<0 || j>=n || vis[i][j])
		return ;
	vis[i][j]=true;
	if(grid[i][j]=='S')
		dfs(grid,vis,i+1,j,m,n);
	else if(grid[i][j]=='N')
		dfs(grid,vis,i-1,j,m,n);
	else if(grid[i][j]=='E')
		dfs(grid,vis,i,j+1,m,n);
	else
		dfs(grid,vis,i,j-1,m,n);
}
int solve(vector<string> &grid,int m,int n)
{
	vector<vector<bool> > vis(m,vector<bool>(n,0));
	int i,j;
	int c=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(!vis[i][j])
			{
				c++;
				dfs(grid,vis,i,j,m,n);
			}
		}
	}
	return c;
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
	int m,n;
	cin>>m>>n;
	vector<string> grid(m);
	int i;
	for(i=0;i<m;i++)
		cin>>grid[i];
	cout<<solve(grid,m,n)<<"\n";
	return 0;
}