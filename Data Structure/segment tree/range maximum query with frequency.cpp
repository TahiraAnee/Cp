#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()

struct node{
    ll max=0;
    ll count=0;
};

const ll N = 1e4+8;
ll arr[N];
node tree[N*4];

node merge(node a, node b) {
    if (a.max > b.max) return a;
    if (b.max > a.max) return b;
    return {a.max, a.count + b.count};
}

void segmentTree(ll indx,ll low,ll high)
{
    if(low==high)
    {
        tree[indx].max = arr[low];
        tree[indx].count=1;
        return;
    }
    ll leftside = 2*indx+1;
    ll rightside = 2*indx +2;

    ll mid = low + (high-low)/2;

    segmentTree(leftside, low, mid);
    segmentTree(rightside, mid + 1, high);

    tree[indx] = merge(tree[leftside],tree[rightside]);
}
node query(ll indx,ll low,ll high,ll l,ll r)
{
    if(l>high || r<low) return {INT_MIN,0};
    if(low>=l && high<=r) return tree[indx];

    ll leftside = 2*indx+1;
    ll rightside = 2*indx +2;
    ll mid = low + (high-low)/2;

    node left = query(leftside,low,mid,l,r);
    node right = query(rightside,mid+1,high,l,r);

    return merge(left,right);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    ll f=1;
    while(t--){
        cout<<"Case "<<f++<<": "<<endl;
        ll n,q;
        cin>>n>>q;
        for(ll i=0;i<n;i++)cin>>arr[i];
        segmentTree(0,0,n-1);
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            node ans = query(0,0,n-1,l,r);
            ll mx=ans.count;
            cout<<mx<<endl;

        }

    }
}
