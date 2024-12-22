#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node{
    ll sum,max,min;
    ll Xor;
};

const ll N = 2e5+8;
ll arr[N];
node tree[N*4];

node merge(node a,node b)
{
    node ans;
    ans.sum = a.sum + b.sum;
    ans.max= max(a.max,b.max);
    ans.min = min(a.min,b.min);
    ans.Xor = a.Xor ^ b.Xor ;

    return ans;
}
void segmentTree(ll indx,ll low,ll high)
{
    if(low==high)
    {
        tree[indx].sum = tree[indx].max = tree[indx].min = tree[indx].Xor =arr[low];
        return;
    }
    ll leftside = 2*indx;
    ll rightside = 2*indx +1;

    ll mid = low + (high-low)/2;

    segmentTree(leftside, low, mid);
    segmentTree(rightside, mid + 1, high);

    tree[indx] = merge(tree[leftside],tree[rightside]);
}
node query(ll indx,ll low,ll high,ll l,ll r)
{
    if(l>high || r<low) return {0,0,(ll)1e18,0};
    if(low>=l && high<=r) return tree[indx];

    ll leftside = 2*indx;
    ll rightside = 2*indx +1;
    ll mid = low + (high-low)/2;

    node left = query(leftside,low,mid,l,r);
    node right = query(rightside,mid+1,high,l,r);

    return merge(left,right);
}
void update(ll indx,ll low,ll high,ll i,ll newValue)
{
    if (i < low || i > high) return;
    if(low==high)
    {
        tree[indx].sum = tree[indx].max = tree[indx].min = tree[indx].Xor = newValue;
        return;
    }

    ll leftside = 2*indx;
    ll rightside = 2*indx +1;

    ll mid = low + (high-low)/2;

    update(leftside,low,mid,i,newValue);
    update(rightside,mid+1,high,i,newValue);

    tree[indx] = merge(tree[leftside],tree[rightside]);


}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
        ll n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>arr[i];

        segmentTree(1,1,n);
        ll q;
        cin>>q;
        while(q--)
        {
            ll type;
            cin>>type;

            if(type==1)
            {
                ll i,v;
                cin>>i>>v;
                update(1,1,n,i,v);
            }else{
                ll l,r;
                cin>>l>>r;
                node ans = query(1,1,n,l,r);

                cout<<ans.sum<<" ";
                cout<<ans.max<<" ";
                cout<<ans.min<<" ";
                cout<<ans.Xor<<"\n";
            }
        }
        
    
}
