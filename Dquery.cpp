#include<bits/stdc++.h>
using namespace std;

int rootN;
const int N= 200000;

struct Q
{
	int idx,l,r;
};
Q q[N];
bool compare(Q q1,Q q2)
{
	if(q1.l/rootN == q2.l/rootN)
		return q1.r>q2.r;
	else
		return q1.l<q2.l;
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
	int n;
	cin>>n;
	rootN=sqrtl(n);
	vector<int> arr(n);
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];
	int queries;
	cin>>queries;
	int freq[1000001];
	memset(freq,0,sizeof(freq));
	for(i=0;i<queries;i++)
	{
		int l,r;
		cin>>l>>r;
		q[i].l=l-1;
		q[i].r=r-1;
		q[i].idx=i;
	}
	sort(q,q+queries,compare);
	vector<int> ans(queries);
	int curr_l=0,curr_r=-1;
	int curr_ans=0;
	for(i=0;i<queries;i++)
	{
		int l=q[i].l;
		int r=q[i].r;
		while(curr_r<r)
		{
			curr_r++;
			freq[arr[curr_r]]++;
			if(freq[arr[curr_r]]==1)
				curr_ans++;
		}
		while(curr_r>r)
		{
			freq[arr[curr_r]]--;
			if(freq[arr[curr_r]]==0)
				curr_ans--;
			curr_r--;
		}
		while(curr_l<l)
		{
			freq[arr[curr_l]]--;
			if(freq[arr[curr_l]]==0)
				curr_ans--;
			curr_l++;
		}
		while(curr_l>l)
		{
			curr_l--;
			freq[arr[curr_l]]++;
			if(freq[arr[curr_l]]==1)
				curr_ans++;
		}
		ans[q[i].idx]=curr_ans;
	}
	for(i=0;i<queries;i++)
		cout<<ans[i]<<"\n";
	return 0;
}

