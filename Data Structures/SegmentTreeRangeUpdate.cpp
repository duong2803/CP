// https://cses.fi/problemset/task/1651/
// Range update queries
// Time complexity: O(qlog(n))
// Lazy propagation for range update

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll st[1 << 19];
vector<ll> a;
int n, q;

void build(int l = 0, int r = n - 1, int idx = 0){
	if(l == r){
		st[idx] = a[l];
		return;
	}
	int m = l + r >> 1;
	build(l, m, idx * 2 + 1);
	build(m + 1, r, idx * 2 + 2);
}

void upd(int l1, int r1, int u, int l2 = 0, int r2 = n - 1, int idx = 0){
	if(l2 > r1 || r2 < l1) return;
	if(l2 >= l1 && r2 <= r1){
		st[idx] += u;
		return;
	}
	int m = l2 + r2 >> 1;
	upd(l1, r1, u, l2, m, idx * 2 + 1);
	upd(l1, r1, u, m + 1, r2, idx * 2 + 2);
}

ll qry(int k, int l = 0, int r = n - 1, int idx = 0){
	
	if(l == r){
		return st[idx];
	}
	int m = l + r >> 1;
	if(k <= m)
		return st[idx] + qry(k, l, m, idx * 2 + 1);
	else
		return st[idx] + qry(k, m + 1, r, idx * 2 + 2);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(st, 0, sizeof(st));
	cin >> n >> q;
	a.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	build();

	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int l, r, u;
			cin >> l >> r >> u;
			upd(l - 1, r - 1, u);
		}else if(type == 2){
			int k;
			cin >> k;
			cout << qry(k - 1) << '\n';
		}
	}
	return 0;
}
