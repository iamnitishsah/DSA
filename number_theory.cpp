#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000000000000000LL;


// Find Primes
// TC:- O(nlog(log(n)))
// SC:- O(n)
vector<int> find_primes(lli n)
{
    vector<bool> is_prime(n+1, true);
    for(lli i=2; i*i<=n; i++)
    {
        if(is_prime[i])
        {
            for(lli j=1LL*i*i; j<=n; j+=i)
            {
                is_prime[j]=false;
            }
        }
    }

    vector<int> primes;
    for(lli i=2; i<=n; i++)
    {
        if(is_prime[i])
            {primes.push_back(i);}
    }
    return primes;
}


// Prime Factorization

vector<int> factorize(lli n)
{
    vector<int> sp(n+1);
    for(int i=2; i<=n; i++)
        {sp[i]=i;}

    for(int i=2; i<n; i++)
    {
        if(sp[i]==i)
        {
            for(int j=2*i; j<=n; j+=i)
            {
                sp[j]=i;
            }
        }
    }

    vector<int> factors;
    while(n>1)
    {
        factors.push_back(sp[n]);
        n/=sp[n];
    }
    return factors;
}


void solution()
{
    int n; cin>>n;

    // Find Primes
    // vector<int> primes;
    // primes = find_primes(n);
    // for(int nums:primes)
    //     {cout<<nums<<endl;}

    // Factorize
    vector<int> factors=factorize(n);
    for(int factor:factors)
        {cout<<factor<<endl;}
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