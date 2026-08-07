#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr)

#define int long long
#define pb push_back
#define F first
#define S second
#define nl cout<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

const int INF = 1e18;
const int MOD = 1e9+7;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using adj = vector<vector<pii>>;


// precise(upto n==60)
int ncr_precise(int n, int r)
{
    if(r<0 or r>n)
        {return 0;}

    int ans=1;
    for(int i=0; i<r; i++)
    {
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}

// any modulo(upto n=4000)
int ncr_array[4004][4004];
void ncr_any_modulo(int mod)
{
    ncr_array[0][0]=1;
    for(int n=1; n<=4000; n++)
    {
        for(int r=0; r<=n; r++)
        {
            if(r==0 or r==n)
                {ncr_array[n][r]=1;}
            else
                {ncr_array[n][r]=(ncr_array[n-1][r]+ncr_array[n-1][r-1])%mod;}
        }
    }
}

// prime modulo(upto n=400000)
int binpow(int a, int b)
{
    if(b==0)
        {return 1;}

    if(b%2==1)
        {return a*binpow(a, b-1)%MOD;}
    else
    {
        int ans=binpow(a, b/2);
        return (ans*ans)%MOD;
    }
}

void factorial(int n, vi& fact)
{
    fact[0]=1;
    for(int i=1; i<=n; i++)
        {fact[i]=(fact[i-1]*i)%MOD;}
}

vi fact;
int ncr(int n, int r)
{
    if(r<0 or r>n)
        {return 0;}
    int den=(fact[r]*fact[n-r])%MOD;
    return (fact[n]*binpow(den, MOD-2))%MOD;
}


void solution()
{
    int n=400000;
    int r=200000;

    // cout<<ncr_precise(n, r);
    // nl;

    // ncr_any_modulo(MOD);
    // cout<<ncr_array[n][r];
    // nl;

    fact.resize(n+1);
    factorial(n, fact);
    cout<<ncr(n, r);
    nl;
}


signed main()
{
    fast_io();

    int tc=1;
    // cin>>tc;

    while(tc--)
        solution();

    return 0;
}