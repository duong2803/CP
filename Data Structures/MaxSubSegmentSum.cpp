// https://codeforces.com/problemset/problem/1796/D
// Maximum subarray
// Time complexity: O(nlogn)
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct dt{
	ll sum, pref, suff, ans;
};
ll a[200000];
dt st[1<<19];
ll n, k ,x;

dt make_dt(ll k){
	dt res;
	res.sum = k;
	res.pref = res.suff = res.ans = max(0ll, k);
	return res;
}

dt combine(dt l, dt r){
	dt res;
	res.sum = l.sum + r.sum;
	res.pref = max(l.pref, l.sum + r.pref);
	res.suff = max(r.suff, r.sum + l.suff);
	res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
	return res;
}

void bld(int l = 0, int r = n - 1, int idx = 0){
	if(l == r){
		st[idx] = make_dt(a[l]);
		return;
	}
	int m = l + r >> 1;
	bld(l, m, idx * 2 + 1);
	bld(m + 1, r, idx * 2 + 2);
	st[idx] = combine(st[idx * 2 + 1], st[idx * 2 + 2]);
}

void upd(int pos, ll new_val, int l = 0, int r = n - 1, int idx = 0){
	if(l == r){
		st[idx] = make_dt(new_val);
		return;
	}
	int m = l + r >> 1;
	if(pos <= m)
		upd(pos, new_val, l, m, idx * 2 + 1);
	else
		upd(pos, new_val, m + 1, r, idx * 2 + 2);
	st[idx] = combine(st[idx * 2 + 1], st[idx * 2 + 2]);
}

dt qry(int l1 = 0, int r1 = n - 1, int l2 = 0, int r2 = n - 1, int idx = 0){
	if(l2 > r1 || r2 < l1) return make_dt(0);
	if(l2 >= l1 && r2 <= r1) return st[idx];
	int m = l2 + r2 >> 1;
	return combine(qry(l1,r1,l2,m, idx*2+1), qry(l1, r1, m + 1, r2, idx * 2 + 2));
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		cin >> n >> k >> x;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		if(x < 0){
			x = -x;
			k = n - k;
		}	
		for(int i = 0; i < k; ++i){
			a[i] += x;
		}
		for(int i = k; i < n; ++i){
			a[i] -= x;
		}
		bld();
		ll ans = qry().ans;
		if(k == 0){
			cout << ans << '\n';
			continue;
		}
		for(int i = 0; i < n - k; ++i){
			upd(i, a[i] - 2 * x);
			upd(i + k, a[i + k] + 2 * x);
			a[i] -= 2 * x;
			a[i + k] += 2 * x;
			ans = max(ans, qry().ans);
		}
		cout << ans << '\n';
	}	
}
