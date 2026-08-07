#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;


// TC:- O(n^3)
// SC:- O(n^2)
void floyd_warshall(lli n, vector<vector<lli>>& dis)
{
    for(lli via=1; via<=n; via++)
    {
        for(lli from=1; from<=n; from++)
        {
            for(lli to=1; to<=n; to++)
            {
                if(dis[from][via] != INF && dis[via][to] != INF)
                    {dis[from][to]=min(dis[from][to], dis[from][via]+dis[via][to]);}
            }
        }
    }
}


void solution()
{
    lli n, m;
    cin>>n>>m;

    vector<vector<lli>> adjmatrix(n+1, vector<lli>(n+1, INF));

    for(lli i=1;i<=n;i++)
        {adjmatrix[i][i]=0;}

    for(lli i=0;i<m;i++)
    {
        lli u,v,w;
        cin>>u>>v>>w;
        adjmatrix[u][v]=w;
    }

    floyd_warshall(n, adjmatrix);


    for(lli i=1;i<=n;i++)
    {
        if(adjmatrix[i][i]<0)
            {
                cout<<-1;
                return;
            }
    }

    for(lli i=1; i<=n; i++)
    {
        for(lli j=1; j<=n; j++)
        {
            cout<<adjmatrix[i][j]<<" ";
        }
        cout<<endl;
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