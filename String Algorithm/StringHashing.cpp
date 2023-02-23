//https://cses.fi/problemset/task/2420
//Palindrome Queries
//Using rabin karp algorithm for hashing string
//Time complexity: O(qlogn) 
 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 4e5 + 5;
const ll mod = 1e9 + 7;
ll p[mxN];

struct{

	ll fen[mxN];
	void upd(int i, ll n){
		for(;i < mxN; i += i & -i){
			fen[i] += n;
			fen[i] %= mod;
		}
	}

	ll qry(int i){
		ll res = 0;
		for(; i > 0; i -= i & -i){
			res += fen[i];
			res %= mod;
		}
		return res;
	}

}nm, rv;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	string tmp;
	string s = " ";
	cin >> tmp;
	s += tmp;
	p[0] = 1;
	for(int i = 1; i < mxN; ++i){
		p[i] = p[i - 1] * 31;
		p[i] %= mod;
	}

	for(int i = 1; i <= n; ++i){
		nm.upd(i, (s[i] - 'a' + 1) * p[i] % mod);
		rv.upd(i, (s[i] - 'a' + 1) * p[n - i + 1] % mod);
	}

	while(q--){
		int type;
		cin >> type;

		if(type == 1){
			int k;
			char c;
			cin >> k >> c;
			nm.upd(k, (c - s[k] + mod) * p[k] % mod);
			rv.upd(k, (c - s[k] + mod) * p[n - k + 1] % mod);
			s[k] = c;
		}else if(type == 2){
			int l, r;
			cin >> l >> r;
			ll k1 = (nm.qry(r) - nm.qry(l - 1) + mod) % mod;
			ll k2 = (rv.qry(r) - rv.qry(l - 1) + mod) % mod;
			if(k1 * p[n - l + 1] % mod == k2 * p[r] % mod)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
