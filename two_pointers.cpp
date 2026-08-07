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


// Pointers move in same direction
// TC:- O(n)
int freq[100100];
int distcnt=0;

void insert(int x)
{
    if(freq[x]==0)
        {distcnt++;}
    freq[x]++;
}

void reduce(int x)
{
    freq[x]--;
    if(freq[x]==0)
        {distcnt--;}
}

// condition to eat
bool caneat(int x, int k)
{
    bool ok=false;
    insert(x);
    if(distcnt<=k)
        {ok=true;}
    else
        {ok=false;}
    reduce(x);
    return ok;
}

int form1()
{
    int n, k; cin>>n>>k;
    vi arr(n);
    for(int i=0; i<n; i++)
        {cin>>arr[i];}

    int tail=0; int head=-1;
    int ans=0;

    while(tail<n)
    {
        // eat till you can
        while(head+1<n and caneat(arr[head+1], k))
        {
            head++;
            insert(arr[head]);
        }
        // update answer
        ans+=head-tail+1;

        // update head and tail
        if(tail<=head)
        {
            reduce(arr[tail]);
            tail++;
        }
        else
        {
            tail++;
            head=tail-1;
        }
    }
    return ans;
}


// Pointers move in opposite direction
int form2()
{
    int n; cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++)
        {cin>>arr[i];}

    int l=0; int r=n-1;
    int ans=0;

    while(l<r)
    {
        ans=max(ans, min(arr[l], arr[r])*(r-l));

        if(arr[l]==arr[r])
            {l++; r--;}
        else if(arr[l]<arr[r])
            {l++;}
        else if(arr[l]>arr[r])
            {r--;}
    }
    return ans;
}


// Pointers in different sequnces
// union
void unite(int n, int m, vi &a, vi &b, vi &union_set)
{
    int i=0, j=0;

    while(i<n and j<m)
    {
        if(a[i]==b[j])
        {
            union_set.pb(a[i]);
            i++;
            j++;
        }
        else if(a[i]<b[j])
        {
            union_set.pb(a[i]);
            i++;
        }
        else
        {
            union_set.pb(b[j]);
            j++;
        }
    }

    while(i<n)
    {
        union_set.pb(a[i]);
        i++;
    }

    while(j<m)
    {
        union_set.pb(b[j]);
        j++;
    }
}

void intersect(int n, int m, vi &a, vi &b, vi &intersection_set)
{
    int i=0, j=0;

    while(i<n and j<m)
    {
        if(a[i]==b[j])
        {
            intersection_set.pb(a[i]);
            i++;
            j++;
        }
        else if(a[i]<b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

void form3()
{
    int n, m;
    cin>>n>>m;

    vi a(n), b(m);
    sort(all(a));
    sort(all(b));

    for(int &x : a)
        {cin >> x;}
    for(int &x : b)
        {cin >> x;}

    // union
    vi union_set;
    unite(n, m, a, b, union_set);
    for(int x : union_set)
        cout << x << " ";
    nl;

    // intersection
    vi intersection_set;
    intersect(n, m, a, b, intersection_set);
    for(int x : intersection_set)
        cout << x << " ";
    nl;
}


void solution()
{
    // Pointers move in same direction
    cout<<form1();
    nl;

    // Pointers move in opposite direction
    cout<<form2();
    nl;

    // Pointers in different sequnces
    form3();
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