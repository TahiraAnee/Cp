// double hashing + single hashing
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
const ll mod=1e9+9,N=1e6+7,mod2=1e9+7;
ll base=131;
ll base2=137;

vector<ll>power(N);
vector<ll>power2(N);
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string text,pat;
    cin>>text>>pat;
    ll n=text.size(),m=pat.size();

    power[0]=1;
    for(ll i=1;i<N;i++)
    {
        power[i]=(power[i-1]*base)%mod;

    }
    power2[0]=1;
    for(ll i=1;i<N;i++)
    {
        power2[i]=(power2[i-1]*base2)%mod2;

    }

    vector<ll>hash_T(n+1,0);
    for(ll i=0;i<n;i++)
    {
        hash_T[i+1]=(hash_T[i]+(text[i]-'a'+1)*power[i])%mod;

    }
    ll hash_P=0;

    for(ll i=0;i<m;i++)
    {
        hash_P = (hash_P+ (pat[i]-'a'+1)*power[i])%mod;
    }

    vector<ll>hash_T2(n+1,0);
    for(ll i=0;i<n;i++)
    {
        hash_T2[i+1]=(hash_T2[i]+(text[i]-'a'+1)*power2[i])%mod2;

    }
    ll hash_P2=0;

    for(ll i=0;i<m;i++)
    {
        hash_P2 = (hash_P2+ (pat[i]-'a'+1)*power2[i])%mod2;
    }

    ll ans=0;

    for(ll i=0;i<n-m+1;i++)
    {
        ll cur_hash=(hash_T[i+m]-hash_T[i]+mod)%mod;
        ll cur_hash2=(hash_T2[i+m]-hash_T2[i]+mod2)%mod2;
        if((cur_hash==(hash_P*power[i])%mod) && (cur_hash2==(hash_P2*power2[i])%mod2)  )
        {
            ans++;
        }
    }

    cout<<ans<<endl;
}
