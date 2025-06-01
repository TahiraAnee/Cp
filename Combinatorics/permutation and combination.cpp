#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()

const int N=1e6+2,mod=1e9+7;

ll power(ll n,ll k)
{
    ll ans= 1%mod;
    n%=mod;
    if(n<0)n+=mod;
    while(k)
    {
        if(k&1)ans=(long long) ans*n%mod;
        n=(long long) n*n%mod;
        k>>=1;
    }
    return ans;
}
ll f[N],invf[N];
ll nCr(ll n , ll r)
{
    if(n<r or n<0)return 0;
    return (1LL * f[n] %mod * invf[r]%mod * invf[n-r]%mod)%mod;
}
ll nPr(ll n,ll r)
{
    if(n<r or n<0) return 0;
     return (1LL * f[n] %mod * invf[n-r]%mod)%mod;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // O(n) e factorial ber kora
    f[0]=1;
    for(ll i=1;i<N;i++)
    {
        f[i]=1LL*i*f[i-1]%mod;
    }
    // O(n) e invfactorial ber kora
    invf[N-1]=power(f[N-1],mod-2);
    for(ll i=N-2;i>=0;i--)
    {
        invf[i]=1LL * invf[i+1]*(i+1)%mod;
    }
    
       ll n,r;
       cin>>n>>r;
       cout<<nCr(6,2)<<endl;
       cout<<nPr(6,2)<<endl;
    
}
