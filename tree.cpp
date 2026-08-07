#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;


vector<vector<lli>> adj;
vector<lli> depth;
vector<lli> parent;
vector<bool> isleaf;
vector<lli> subtree_size;
vector<lli> no_of_child;


void dfs(lli node, lli par, lli dep)
{
    depth[node]=dep;
    parent[node]=par;

    subtree_size[node]=1;
    no_of_child[node]=0;

    for(auto neigh : adj[node])
    {
        if(neigh!=parent[node])
        {
            no_of_child[node]++;
            dfs(neigh, node, dep+1);
            subtree_size[node]+=subtree_size[neigh];
        }

    }

    if(no_of_child[node]==0)
        {isleaf[node]=1;}
}


void solution()
{
    lli n;
    cin>>n;
    adj.resize(n+1);
    depth.resize(n+1);
    parent.resize(n+1);
    isleaf.resize(n+1);
    subtree_size.resize(n+1);
    no_of_child.resize(n+1);


    for(lli i=0; i<n-1; i++)
    {
        lli a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    lli u, v;
    cin>>u>>v;

    dfs(u, 0, 0);


    // distance
    cout<<"Distance from "<<u<<" to "<<v<<":"<<depth[v]-depth[u]<<endl;


    // path
    string path="paths:-";
    lli curr=v;
    while(curr!=u and curr!=0)
    {
        path+=to_string(curr);
        path+="<-";
        curr=parent[curr];
    }
    path+=to_string(curr);
    cout<<path<<endl;


    // diameter
    lli farthest_node=1;
    for(lli i=2; i<=n; i++)
    {
        if(depth[i]>depth[farthest_node])
            {farthest_node=i;}
    }

    dfs(farthest_node, 0, 0);
    
    lli dia_end=1;
    for(lli i=2; i<=n; i++)
    {
        if(depth[i]>depth[dia_end])
            {dia_end=i;}
    }
    cout<<"diameter of tree = "<<depth[dia_end]-depth[farthest_node]<<endl;
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