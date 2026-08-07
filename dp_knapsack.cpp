#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;


int n, w;
vector<int> weight, value;
vector<vector<int>> dp;
vector<int> choices;


// TC:O(n*w)
int knapsack(int i, int w)
{
	if(i==n)
		{return 0;}

	if(dp[i][w]!=-1)
		{return dp[i][w];}

	int notpick=knapsack(i+1, w);

	int pick=0;
	if(weight[i]<=w)
	{
		// 0-1 knapsack
		pick=knapsack(i+1, w-weight[i])+value[i];
		// infinite knapsack
		// pick=knapsack(i, w-weight[i])+value[i];
	}

	int ans=max(pick, notpick);
	dp[i][w]=ans;
	return ans;
}

void generate(int i, int w)
{
	if(i==n)
		{return;}

	int take=0;
	int donttake=0;

	// possibility: can take
	if(weight[i]<=w)
	{
		// choice: take
		// 0-1 knapsack
		take=knapsack(i+1, w-weight[i])+value[i];
		// infinite knapsack
		// take=knapsack(i, w-weight[i])+value[i];

		// choice: don't take
		donttake=knapsack(i+1, w);

		// move
		if(take>=donttake)
		{
			choices.pb(i);
			// 0-1 knapsack
			generate(i+1, w-weight[i]);
			// infinite knapsack
			// generate(i, w-weight[i]);
		}
		else
			{generate(i+1, w);}
	}
	// possibility: can't take
	else
		{generate(i+1, w);}
}


void solution()
{
	cin>>n>>w;

	weight.resize(n);
	value.resize(n);
	dp.resize(n+1, vector<int>(w+1, -1));

	for(int i=0; i<n; i++)
		{cin>>weight[i];}

	for(int i=0; i<n; i++)
		{cin>>value[i];}


	int ans=knapsack(0, w);
	cout<<ans<<endl;

	generate(0, w);

	cout<<choices.size()<<endl;
	for(int i=0; i<choices.size(); i++)
		{cout<<choices[i]<<" ";}
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