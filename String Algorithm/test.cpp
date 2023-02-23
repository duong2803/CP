#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN= 4e5 + 5;
struct{
	
	ll fen[mxN] = {};
	void upd(int i, ll n){
		for(;i < mxN; i += i & -i) {
			fen[i] += n; 

		}
	}
	ll qry(int i){
		ll res = 0;
		for(; i >= 1; i -= i & -i){
		   	res += fen[i];

		}
		return res;
	}
		
}nm, rv;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		nm.upd(i, a[i]);
	}
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int l, r;
			cin >> l >> r;
			nm.upd(l, r - a[l]);
			a[l] = r;
		}else if(type == 2){
			int l , r;
			cin >> l >> r;
			cout << nm.qry(r) - nm.qry(l - 1) << '\n';
		}
	}
}

