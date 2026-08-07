#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;

vector<vector<int>> g;
vector<int> vis;
vector<int> topo; 

void dfs(int node)
{
    vis[node]=1;
    for(auto v : g[node])
    {
        if(!vis[v])
        {dfs(v);}
    }
    topo.pb(node);
}


void solution()
{
    int n, m;
    cin>>n>>m;
    vis.assign(n+1, 0);
    g.resize(n+1);
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            {dfs(i);}
    }
    reverse(topo.begin(), topo.end());
    for(int node:topo)
        {cout<<node<<endl;}

    // longest path in DAG
    vector<int> dp(n+1, 0);

    for(auto u : topo)
    {
        for(auto v : g[u])
        {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}


int main()
{
    fast_io();

    int t=1;
    // cin>>t;
    while(t--)
    {solution();}

    return 0;
}