#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;

vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;

void kahn(int n)
{
    priority_queue<int> pq;

    for(int i=1; i<=n; i++)
    {
        if(indeg[i]==0)
            {pq.push(-i);}
    } 

    while(!pq.empty())
    {
        int curr=-pq.top();
        pq.pop();
        topo.pb(curr);
        for(auto neigh:g[curr])
        {
            indeg[neigh]--;
            if(indeg[neigh]==0)
                {pq.push(-neigh);}
        }
    }
}


void solution()
{
    int n, m;
    cin>>n>>m;
    g.resize(n+1);
    indeg.resize(n+1);
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].pb(b);
        indeg[b]++;
    }

    kahn(n);

    if(topo.size()!=n)
        {cout<<"Cyclic Graph\n";}
    else
    {
        for(auto node:topo)
        {cout<<node<<endl;}
    }
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