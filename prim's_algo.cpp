#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;

lli v, e;
vector<vector<pair<lli, lli>>> adj;
lli sum;

// TC:- O(elog(v))
// SC:- O(v+e)
void prim()
{
    priority_queue<pair<lli, lli>> pq;
    vector<bool> vis(v+1, false);
    pq.push({-0, 1});
    sum=0;

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        lli node=it.second;
        lli weig=it.first;

        if(vis[node]==true)
            {continue;}
        vis[node]=true;

        sum+=(-weig);

        for(auto neigh : adj[node])
        {
            lli nd=neigh.first;
            lli wt=neigh.second;

            if(!vis[nd])
            {
                pq.push({-wt, nd});

            }
        }
    }
}


void solution()
{
    cin>>v>>e;
    adj.resize(v+1);

    for(lli i=0; i<e; i++)
    {
        lli a, b, w;
        cin>>a>>b>>w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    prim();

    cout<<sum;
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