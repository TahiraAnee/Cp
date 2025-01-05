#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
const ll N=2e5+12;
ll tree[N];
ll arr[N];
ll query(ll index)
{
    ll sum =0;
    while(index)
    {
        sum+=tree[index];
        index-=(index & (-index));
    }

    return sum;
}
void update(ll index,ll val,ll n)
{
    while(index<=n)
    {
        tree[index] +=val;
        index += (index & (-index));
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(i,arr[i],n);
    }

    while(q--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll ind,val;
            cin>>ind>>val;
          //  val=abs(arr[ind]-val); if i want to set arr[ind] to val;otherwise this code will give me increased values only.
            update(ind,val,n);

        }else
        {
            ll l,r;
            cin>>l>>r;
            ll ans= query(r)-query(l-1);
            cout<<ans<<endl;
        }
    }
}
