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
using adj = vector<vector<pair<int, int>>>;


class Node
{
public:
    int val;
    Node(int x=0)
        {val=x;}
};

Node merge(Node left, Node right)
{
    Node ans;
    ans.val=left.val+right.val;
    return ans;
}

int n;
vi arr;
vector<Node> tree;

void build(int ind, int l, int r)
{
    if(l==r)
    {
        tree[ind]=Node(arr[l]);
        return;
    }

    int mid=l+(r-l)/2;

    build(2*ind, l, mid);

    build(2*ind+1, mid+1, r);

    tree[ind]=merge(tree[2*ind], tree[2*ind+1]);
}

void update(int ind, int l, int r, int pos, int val)
{
    if(pos<l or pos>r)
        {return;}

    if(l==r)
    {
        arr[l]=val;
        tree[ind]=Node(arr[l]);
        return;
    }

    int mid=l+(r-l)/2;

    update(ind*2, l, mid, pos, val);
    update(ind*2+1, mid+1, r, pos, val);

    tree[ind]=merge(tree[2*ind], tree[2*ind+1]);
}

Node query(int ind, int l, int r, int ql, int qr)
{
    if(r<ql or qr<l)
        {return Node();}

    if(ql<=l and r<=qr)
        {return tree[ind];}

    int mid=l+(r-l)/2;

    Node left=query(ind*2, l, mid, ql, qr);
    Node right=query(ind*2+1, mid+1, r, ql, qr);
    return merge(left, right);
}

void solution()
{
    cin>>n;
    int q; cin>>q;
    arr.resize(n);
    tree.resize(4*n+1);
    for(int i=0; i<n; i++)
        {cin>>arr[i];}

    build(1, 0, n-1);

    // for(int x:tree)
    //     {cout<<x<<" ";}

    for(int i=0; i<q; i++)
    {
        int typ;
        cin>>typ;
        if(typ==1)
        {
            int pos, val;
            cin>>pos>>val;
            pos--;
            update(1, 0, n-1, pos, val);
        }
        else if(typ==2)
        {
            int l, r;
            cin>>l>>r;
            l--; r--;
            Node ans=query(1, 0, n-1, l, r);
            cout<<ans.val;
            nl;
        }
    }
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