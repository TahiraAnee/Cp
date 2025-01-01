#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=1e5+6;
ll arr[N];
ll tree[N*3],lazy[N*3];

void segmentTree(ll indx,ll low,ll high)
{
    if(low==high)
    {
        tree[indx] =arr[low];
        return;
    }

    ll leftside = indx*2;
    ll rightside = indx*2+1;
    ll mid = (low+high)>>1;

    segmentTree(leftside,low,mid);
    segmentTree(rightside,mid+1,high);

    tree[indx] = tree[leftside] + tree[rightside];

}
void rangeUpdate(ll indx,ll low,ll high,ll l,ll r,ll val)
{
    if(lazy[indx]!=0)
    {
        tree[indx] +=(high-low+1)*lazy[indx];
        if(low!=high)
        {
            lazy[2*indx]+=lazy[indx];
            lazy[2*indx+1]+=lazy[indx];
        }
        lazy[indx]=0;
    }
    
    if(r<low || l>high || low>high) return;
    if(low>=l && high<=r){
         tree[indx] +=(high-low+1)*val;
        if(low!=high)
        {
            lazy[2*indx]+=val;
            lazy[2*indx+1]+=val;
        } return; 
    }
    ll mid=(low+high)>>1;
    rangeUpdate(2*indx,low,mid,l,r,val);
    rangeUpdate(2*indx+1,mid+1,high,l,r,val);

    tree[indx] = tree[2*indx] +tree[2*indx+1];

}
int sumQueryLazy(ll indx,ll low,ll high,ll l,ll r)
{
    if(lazy[indx]!=0)
    {
        tree[indx] +=(high-low+1)*lazy[indx];
        if(low!=high)
        {
            lazy[2*indx]+=lazy[indx];
            lazy[2*indx+1]+=lazy[indx];
        }
        lazy[indx]=0;
    }

    if(r<low || l>high || low>high) return 0;
    if(low>=l && high<=r){
        return tree[indx];
    }
    ll mid=(low+high)>>1;

    return sumQueryLazy(2*indx,low,mid,l,r) + 
            sumQueryLazy(2*indx+1,mid+1,high,l,r);

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
    }
    segmentTree(1,1,n);

    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='U')
        {
            ll l,r,val;
            cin>>l>>r>>val;
            rangeUpdate(1,1,n,l,r,val);
        }else
        {
            ll l,r;
            cin>>l>>r;
            cout<<sumQueryLazy(1,1,n,l,r)<<endl;
        }

    }
}
