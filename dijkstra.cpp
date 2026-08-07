#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;

lli n, m;
vector<vector<pair<lli, lli>>> adj;
vector<lli> dist;
vector<bool> vis;


// Priority Queue
void dijkstra_pq(lli sc)
{
    priority_queue<pair<lli, lli>> pq;
    pq.push({-0, sc});
    dist[sc]=0;

    while(!pq.empty())
    {
        pair<lli, lli> node = pq.top();
        pq.pop();

        if(vis[node.second])
            {continue;}
        else{vis[node.second]=true;}

        for(auto v : adj[node.second])
        {
            lli neigh = v.first;
            lli weigh = v.second;

            if(dist[neigh]>dist[node.second]+weigh)
            {
                dist[neigh] = dist[node.second]+weigh;
                pq.push({-dist[neigh], neigh});
            }
        }
    }
}


// Set
void dijkstra_set(lli sc)
{
    dist[sc]=0;

    set<pair<lli, lli>> st;
    st.insert({dist[sc], sc});

    while(!st.empty())
    {
        auto node = *st.begin();
        st.erase(st.begin());

        if(vis[node.second])
            {continue;}
        else{vis[node.second]=true;}

        for(auto v : adj[node.second])
        {
            lli neigh = v.first;
            lli weigh = v.second;

            if(dist[neigh]>dist[node.second]+weigh)
            {
                if(dist[neigh] != INF)
                    st.erase({dist[neigh], neigh});

                dist[neigh] = dist[node.second]+weigh;
                st.insert({dist[neigh], neigh});
            }
        }
    }
}


void solution()
{
    cin>>n>>m;
    adj.resize(n+1);
    dist.assign(n+1, INF);
    vis.assign(n+1, false);
    for(lli i=0; i<m; i++)
    {
        lli a, b, c;
        cin>>a>>b>>c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    dijkstra_set(1);

    for(lli i=1 ;i<=n ;i++)
        {cout<<"Distance of "<<i<<" : "<<dist[i]<<endl;}
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