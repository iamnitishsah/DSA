#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;

int n, m, l;
string s, t, u;
vector<vector<vector<int>>> dp;

int rec(int i, int j, int k)
{
    if(i==n or j==m or k==l)
        {return 0;}

    if(dp[i][j][k]!=-1)
        {return dp[i][j][k];}

    if(s[i]==t[j] and t[j]==u[k])
        {
            int match = 1+rec(i+1, j+1, k+1);
            dp[i][j][k]=match;
            return match;
        }

    int from_i=rec(i+1, j, k);
    int from_j=rec(i, j+1, k);
    int from_k=rec(i, j, k+1);

    int ans=max(from_i, max(from_j, from_k));
    dp[i][j][k]=ans;
    return ans;
}


void solution()
{
    cin>>n>>m>>l;
    cin>>s>>t>>u;
    dp.assign(n, vector<vector<int>>(m, vector<int>(l, -1)));
    cout<<rec(0, 0, 0)<<endl;
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