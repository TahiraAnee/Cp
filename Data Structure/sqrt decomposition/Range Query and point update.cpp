#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Sqrt {
	ll block_size;
	vector<ll> nums;
	vector<ll> blocks;
	Sqrt(ll sqrtn, vector<ll> &arr) : block_size(sqrtn), blocks(sqrtn, 0) {
		nums = arr;
		for (ll i = 0; i < nums.size(); i++) { blocks[i / block_size] += nums[i]; }
	}

	/** O(1) update to set nums[x] to v */
	void update(ll x, ll v) {
		blocks[x / block_size] -= nums[x];
		nums[x] = v;
		blocks[x / block_size] += nums[x];
	}

	/** O(sqrt(n)) query for sum of [0, r) */
	ll query(ll r) {
		ll res = 0;
		for (ll i = 0; i < r / block_size; i++) { res += blocks[i]; }
		for (ll i = (r / block_size) * block_size; i < r; i++) { res += nums[i]; }
		return res;
	}

	/** O(sqrt(n)) query for sum of [l, r) */
	ll query(ll l, ll r) { return query(r) - query(l - 1); }
};

int main() {
	ll n, q;
	cin >> n >> q;

	vector<ll> arr(n);
	for (ll i = 0; i < n; i++) { cin >> arr[i]; }
	Sqrt sq((ll)ceil(sqrt(n)), arr);

	for (ll i = 0; i < q; i++) {
		ll t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			sq.update(l - 1, r);
		} else {
			cout << sq.query(l, r) << "\n";
		}
	}
}
