#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;

int n, c;
vector<int> cuts;
vector<vector<int>> dp;

int rec(int i, int j)
{
    // base case
    // no index b/w range
    if(j-i==1)
        {return 0;}

    // cache check
    if(dp[i][j]!=-1)
        {return dp[i][j];}

    // compute
    // iterate over all index b/w range(i, j) and cut there
    int ans=1e9;
    for(int c=i+1; c<j; c++)
        {
            int left_best=rec(i, c);
            int right_best=rec(c, j);
            int curr_cost=cuts[j]-cuts[i];
            ans=min(ans, curr_cost+left_best+right_best);
        }

    // save and return
    dp[i][j]=ans;
    return ans;
}


void solution()
{
    cin>>n;
    cin>>c;

    cuts.resize(c);
    for(int i=0; i<c; i++)
        {cin>>cuts[i];}

    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int m=cuts.size();
    dp.assign(m+1, vector<int>(m+1, -1));
    int ans=rec(0, m-1);
    cout<<ans;
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