#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define Pair pair<long,long>
#define optimize() ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
void computeLPS(string &b, vector<ll>&LPS,ll m)
{
    ll len=0;
    int i=1;
    LPS[0]=0;
    while(i<m)
    {
        if(b[i]==b[len])
        {
            len++;
            LPS[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=LPS[len-1];

            }
            else
            {
                LPS[i]=0;
                i++;
            }
        }
    }
}
ll computeKMP(string &a,string &b,vector<ll>&LPS,ll n,ll m)
{
    ll cnt=0;
    ll i=0,j=0;
    while(i<n)
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }

        if(j==m)
        {
            // found
            cnt++;
            j=LPS[j-1];
        }
        else if(a[i]!=b[j])
        {
            if(j!=0)
            {
                j=LPS[j-1];
            }else i++;
        }
    }

    return cnt;
}

int main()
{
    optimize();
    ll t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        string a,b;
        cin>>a>>b;
        ll n=a.size(),m=b.size();
        vector<ll>LPS(m,0);
        computeLPS(b,LPS,m);
        ll ans=computeKMP(a,b,LPS,n,m);

        cout<<ans<<endl;

    }
}
