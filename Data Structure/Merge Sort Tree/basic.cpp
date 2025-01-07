#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// *s.find_by_order(index), s.order_of_key(value)
// erase -> s.erase(s.upper_bound(value));


const ll N=1e5+7;
ll arr[N];
ordered_set<ll> node[N*4];

void mergeSortTree(ll curN,ll lo,ll hi)
{
    if(lo==hi)
    {
        node[curN].insert(arr[lo]);
        return;
    }

    ll leftN=curN*2;
    ll rightN=curN*2+1;
    ll mid = lo + (hi-lo)/2;

    mergeSortTree(leftN,lo,mid);
    mergeSortTree(rightN,mid+1,hi);
    for(auto &u:node[leftN])node[curN].insert(u);
    for(auto &u:node[rightN])node[curN].insert(u);
}
void update(ll curN,ll lo,ll hi,ll i,ll val)
{
    if(i>hi || i<lo) return;
    if(lo==hi)
    {
        node[curN].erase(node[curN].upper_bound(arr[i]));
        node[curN].insert(val);
        return;
    }

    ll leftN=curN*2;
    ll rightN=curN*2+1;
    ll mid = lo + (hi-lo)/2;

    update(leftN,lo,mid,i,val);
    update(rightN,mid+1,hi,i,val);

    node[curN].erase(node[curN].upper_bound(arr[i]));
    node[curN].insert(val);
}
ll query(ll curN,ll lo,ll hi,ll i,ll j,ll x)
{
    if(i>hi || j<lo) return 0;
    if(lo>=i && hi<=j)
    {
        ll ans=node[curN].order_of_key(x+1);
        ll total=hi-lo+1;

        return total-ans;
    }

    ll leftN=curN*2;
    ll rightN=curN*2+1;
    ll mid = lo + (hi-lo)/2;

    return query(leftN,lo,mid,i,j,x) + query(rightN,mid+1,hi,i,j,x);

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n;
    cin>>n;

    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    mergeSortTree(1,1,n);

    ll q;
    cin>>q;
    while(q--)
    {
        ll p;
        cin>>p;
        if(p==1)
        {
            // update
            ll i,v;
            cin>>i>>v;
            update(1,1,n,i,v);
            arr[i]=v;
        }
        else
        {
            ll i,j,k;
            cin>>i>>j>>k;
            cout<<query(1,1,n,i,j,k)<<endl;
        }
    }
}

