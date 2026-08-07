#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;

vector<int> dp;

int rec(int x)
{
    // base case
    if(x==0)
        {return 0;}

    // cache check
    if(dp[x]!=-1)
        {return dp[x];}

    // compute
    int ans=0;
    for(int m=0; (1<<m)<=x; m++)
    {
        if(rec(x-(1<<m))==0)
        {
            ans=1;
            break;        
        }
    }


    // save
    dp[x]=ans;

    // return
    return ans;
}


void solution()
{
    int n;
    cin>>n;

    dp.assign(n+1, -1);

    bool ans=rec(n);

    if(ans)
        {cout<<"WIN\n";}
    else{cout<<"LOSE\n";}
}


signed main()
{
    fast_io();

    lli t=1LL;
    cin>>t;
    while(t--)
    {solution();}

    return 0;
}