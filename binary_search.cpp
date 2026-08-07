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


// TC:- O(log(n))
int n, k;
vi arr;

bool check(int mid)
{
    int req_painter=1;
    int time_used=0;
    for(int i=0; i<n; i++)
    {
        if(time_used+arr[i]>mid)
        {
            req_painter++;
            time_used=arr[i];
        }
        else
        {
            time_used+=arr[i];
        }
    }

    if(req_painter>k)
        {return false;}
    return true;
}

int search(int lo, int hi)
{
    int ans=-1;

    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;

        if(check(mid))
        {
            ans=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    return ans;
}

void solution()
{
    cin>>n>>k;
    arr.resize(n);

    int lo=-1; int hi=0;

    for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            lo=max(lo, arr[i]);
            hi+=arr[i];
        }

    int ans=search(lo, hi);

    cout<<ans;
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