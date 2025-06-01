#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
const int N = 1006,mod=1e9+7;
vector<vector<ll>>Pascal(N,vector<ll>(N,0));
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Pascal[0][0]=1;
    for(ll n=1;n<N;n++)
    {
        Pascal[n][0]=1;
        for(ll k=1;k<=n;k++)
        {
            Pascal[n][k]=(Pascal[n-1][k-1]+Pascal[n-1][k])%mod;
        }
    }

    cout<<Pascal[6][2]<<endl;
    
}
