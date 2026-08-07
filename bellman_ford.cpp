#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;

// TC:- O(n*m);
// SC:- O(m+n);
void bellman_ford(int n, vector<vector<lli>>& edg, vector<lli>& dist)
{
    for(lli i=0; i<n-1; i++)
    {
        for(auto it : edg)
        {
            lli u=it[0];
            lli v=it[1];
            lli wt=it[2];

            if(dist[u]!=INF and dist[v]>dist[u]+wt)
            {
                dist[v]=dist[u]+wt;
            }
        }
    }

    // nth relaxation to check negative cycle
    for(auto &it : edg)
    {
        lli u=it[0];
        lli v=it[1];
        lli wt=it[2];

        if(dist[u]!=INF and dist[v]>dist[u]+wt)
        {
            dist.assign(n+1, -1);
        }
    }
}


void solution()
{
    lli n, m;
    cin>>n>>m;
    // edge list NOT adj list
    vector<vector<lli>> edg;
    vector<lli> dist(n+1, INF);

    for(lli i=0; i<m; i++)
    {
        lli a, b, c;
        cin>>a>>b>>c;
        edg.pb({a, b, c});
    }

    lli sc;
    cin>>sc;
    dist[sc]=0;

    bellman_ford(n, edg, dist);

    for(lli i=1; i<=n; i++)
    {
        cout<<dist[i]<<" ";
    }
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