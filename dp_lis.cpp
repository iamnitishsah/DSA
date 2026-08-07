#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;


int n;
vector<int> arr, dp, parent;

int rec(int level)
{
	// pruning

	// base case

	// cache check
	if(dp[level]!=-1)
		{return dp[level];}

	// computation
	int ans=1;
	for(int i=0; i<level; i++)
	{
		if(arr[i]<arr[level])
		{
			if(1+rec(i)>ans)
			{
				ans=1+rec(i);
				parent[level]=i;
			}
		}
	}

	// save ans return
	dp[level]=ans;
	return ans;
}


void solution()
{
	cin>>n;
	arr.resize(n);
	dp.assign(n, -1);
	parent.assign(n, -1);

	for(int i=0; i<n; i++)
		{cin>>arr[i];}

	// TC:- O(n*n)
	// int best=1;
	// int last_index=-1;
	// for(int i=0; i<n; i++)
	// {
	// 	int len=rec(i);
	// 	if(len>=best)
	// 	{
	// 		best=len;
	// 		last_index=i;
	// 	}
	// }

	// vector<int> lis;
	// while(last_index!=-1)
	// {
	// 	lis.push_back(arr[last_index]);
	// 	last_index=parent[last_index];
	// }

	// reverse(lis.begin(), lis.end());

	// for(auto x:lis)
	// 	{cout<<x<<" ";}


	// TC:- O(nlog(n))
	vector<int> best;
	vector<int> inseted_at(n);
	for(int i=0; i<n; i++)
	{
		if(best.empty() or best.back()<arr[i])
			{
				best.push_back(arr[i]);
				inseted_at[i]=best.size();
			}
		else
		{
			auto it=lower_bound(best.begin(), best.end(), arr[i]);
			*it=arr[i];
			inseted_at[i]=it-best.begin()+1;
		}
	}
	cout<<best.size()<<endl;
	// // print
	// vector<int> lis;
	// int curlen=best.size();
	// for(int i=n-1; i>=0; i--)
	// {
	// 	if(inseted_at[i]==curlen)
	// 		{
	// 			lis.push_back(arr[i]);
	// 			curlen--;
	// 		}
	// }
	// reverse(lis.begin(), lis.end());
	// for(int num:lis)
	// 	{cout<<num<<" ";}
}


signed main()
{
    fast_io();

    lli t=1LL;
    // cin>>t;
    while(t--)
    {solution();}

    return 0;
}