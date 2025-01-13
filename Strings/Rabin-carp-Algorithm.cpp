#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define optimize() ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
const int M=1e9+7,N=1e5+7;
int base=31;
vector<ll>power(N);
int main()
{
    optimize();
    string text,pattern;
    cin>>text>>pattern;
    ll n=text.size(),m=pattern.size(); 
    
    power[0]=1;
    for(ll i=1;i<N;i++)
    {
        power[i]=(power[i-1]*base)%M;
    }
   
    vector<ll>hT(n+2,0);
    for(ll i=0;i<n;i++)
    {
        hT[i+1]=(hT[i]+ (text[i]-'a'+1)*power[i])%M;

    }
    ll hasp=0;

    for(ll i=0;i<m;i++)
    {
        hasp =(hasp+(pattern[i]-'a'+1)*power[i])%M;
    }

    for(ll i=0;i<n-m+1;i++)
    {
        ll curr_h=(hT[i+m]-hT[i]+M)%M;

        if(curr_h==(hasp*power[i])%M)
        {
            cout<<"found at index : "<<i<<endl;
        }
    }

}
