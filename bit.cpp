#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr)

#define int long long
#define pb push_back
#define F first
#define S second
#define nl cout<<"\n";
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

const int INF = 1e18;
const int MOD = 1e9 + 7;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using adj = vector<vector<pii>>;


// TC:- O(n*2^n)
void subset()
{
    int n; cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++)
        {cin>>arr[i];}

    for(int mask=0; mask<(1<<n); mask++)
    {
        cout<<mask+1<<" : ";
        for(int i=0; i<n; i++)
        {
            if((mask>>i)&1)
                {cout<<arr[i]<<", ";}
        }
        nl;
    }
}

// TC:- O(n*3^n)
void subsetofsubset()
{
    int n; cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++)
        {cin>>arr[i];}

    for(int mask=0; mask<(1<<n); mask++)
    {
        cout<<bitset<4>(mask).to_string();
        nl;
        for(int submask=mask; ; submask=((submask-1)&mask))
        {
            cout<<bitset<4>(submask).to_string()<<" : ";
            for(int i=n-1; i>=0; i--)
            {
                if((submask>>i)&1)
                    {cout<<arr[i]<<", ";}
            }
            nl;
            if(submask==0)
                {break;}
        }
        nl;
    }
}


/*
    XOR Rules

    1. a^0=a
    2. a^a=0
    3. a^b=b^a
    4. (a^b)^c=a^(b^c)
    5. a^b^a=b
    6. a^b^c=b^a^c

    7. 0^0=0
    8. 0^1=1
    9. 1^0=1
    10. 1^1=0

    11. if a^b=c
        then b^c=a and a^c=b

    12. Range XOR Pattern
        XOR from 0 to n:

        n % 4 == 0  than n
        n % 4 == 1  than 1
        n % 4 == 2  than n + 1
        n % 4 == 3  than 0

        Hence,
        XOR(L...R) = XOR(0...R) ^ XOR(0...(L-1))
*/
int xor_till(int x)
{
    int ans;

    if(x%4==0)
        {ans=x;}
    else if(x%4==1)
        {ans=1;}
    else if(x%4==2)
        {ans=x+1;}
    else if(x%4==3)
        {ans=0;}

    return ans;
}

void do_xor()
{
    int l , r;
    cin>>l>>r;

    int rxor=xor_till(r);
    int lxor=xor_till(l-1);

    int ans=rxor^lxor;
    cout<<ans;
    nl;
}


void solution()
{
    // make subset
    // subset();

    // make subset of subset
    // subsetofsubset();

    // XOR
    do_xor();
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