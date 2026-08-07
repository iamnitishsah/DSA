#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;

// TC/operation:- O(1);
// SC:- O(n);
class UnionFind
{
private:
    vector<int> parent;
    vector<int> size;
    int no_of_set;

public:
    UnionFind(int n)
    {
        no_of_set=n;
        parent.resize(n+1);
        for(int i=1; i<=n; i++)
            {parent[i]=i;}
        size.assign(n+1, 1);
    }

    int find(int x)
    {
        if(parent[x]==x)
            {return x;}

        int ultimate=find(parent[x]);

        return parent[x]=ultimate;
    }

    void merge(int x, int y)
    {
        int par_x=find(x);
        int par_y=find(y);

        if(par_x==par_y)
            {return;}

        if(size[par_x]<size[par_y])
        {
            size[par_y]+=size[par_x];
            parent[par_x]=par_y;
        }
        else
        {
            size[par_x]+=size[par_y];
            parent[par_y]=par_x;
        }
        no_of_set--;
    }

    void reset(int n)
    {
        parent.resize(n+1);
        size.assign(n+1, 1);
        no_of_set=n;
        for(int i=1; i<=n; i++)
            {parent[i]=i;}
    }
};


void solution()
{
    
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