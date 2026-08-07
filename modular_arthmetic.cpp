#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define pb push_back

const lli MOD = 1000000007LL;
const lli INF = 1000000005LL;


/*
Rules

Addition:
    (a+b)%MOD=(a%MOD + b%MOD)%MOD

Subtraction:
    (a-b)%MOD=((a%MOD - b%MOD)+MOD)%MOD

Multiplication:
    (a*b)%MOD=(a%MOD * b%MOD)%MOD

Division:
    (a/b)%MOD=(a*b^-1)%MOD=(a%MOD * (b^-1)%MOD)%MOD
    where
        b^-1=binpow(b, MOD-2, MOD)
*/


lli binpow(lli base, lli power)
{
    base %= MOD;

    lli ans = 1;

    while(power)
    {
        if(power & 1)
            ans = (ans * base) % MOD;

        base = (base * base) % MOD;
        power >>= 1;
    }

    return ans;
}


void solution()
{
    // (a*b-c^d)/e = ??

    lli a, b, c, d, e;
    cin>>a>>b>>c>>d>>e;
    a %= MOD;
    b %= MOD;
    c %= MOD;
    e %= MOD;

    if(e == 0)
    {
        cout << "Inverse does not exist\n";
        return;
    }

    lli mul=(a%MOD * b%MOD) % MOD;

    lli exp=binpow(c, d);

    lli num=((mul%MOD - exp%MOD) + MOD) % MOD;

    lli einv=binpow(e, MOD-2);

    lli div=(num * einv) % MOD;

    cout<<div<<endl;
}


int main()
{
    fast_io();

    int t=1;
    cin>>t;
    while(t--)
    {solution();}

    return 0;
}