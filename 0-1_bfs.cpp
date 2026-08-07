#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;


void bfs01(lli sc, vector<vector<pair<lli, lli>>>& g, vector<lli>& dist)
{
    deque<lli> dq;
    dq.push_back(sc);

    while(!dq.empty())
    {
        lli node=dq.front();
        dq.pop_front();

        for(auto [neigh, weigh]:g[node])
        {
            if(dist[neigh]>dist[node]+weigh)
            {
                dist[neigh]=dist[node]+weigh;
                if(weigh==0)
                    {dq.push_front(neigh);}
                else{dq.push_back(neigh);}
            }
        }
    }
}


void solution()
{
    lli n, m;
    cin>>n>>m;
    vector<vector<pair<lli, lli>>> g(n+1);
    vector<lli> dist(n+1, INF);
    for(lli i=1; i<=m ;i++)
    {
        lli a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    lli sc; // source
    cin>>sc;
    dist[sc]=0;

    bfs01(sc, g, dist);

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