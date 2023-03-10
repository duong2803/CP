//https://codeforces.com/contest/1778/problem/C
//Flexible String

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		string s, s1;
		cin >> s >> s1;
		unordered_map<char, vector<ll>> at;
		for(ll i = 0; i < n; ++i){
			at[s[i]].push_back(i);
		}
		vector<ll> f(n);
		for(ll i = 0; i < n; ++i){
			if(s[i] == s1[i]){
				f[i] = 1;
			}
		}
		if(k == 0){
			ll res = 0;
			ll cnt = 0;
			for(ll i = 0; i < n; ++i){
				if(f[i] == 1){
					++cnt;
				}else{
					res += cnt * (cnt + 1) >> 1;
					cnt = 0;
				}
			}
			res += cnt * (cnt + 1) >> 1;
			cout << res << '\n';
			continue;
		}
		ll max_bit = at.size();
		k = min(k, max_bit);
		ll u = (1 << k) - 1;
		ll v;
		ll res = 0;
		for(ll i = 0;;++i){
			ll mask = 0;
			vector<ll> ff = f;
			for(auto p : at){
				if((u >> mask) & 1){
					for(ll z: p.second){
						ff[z] = 1;
					}
				}
				mask++;
			}
			ll tmp = 0;
			ll cnt = 0;
			for(ll z = 0; z < n; ++z){
				if(ff[z] == 1){
					++cnt;
				}else{
					tmp += cnt * (cnt + 1) >> 1;
					cnt = 0;
				}
			}
			tmp += cnt * (cnt + 1) >> 1;
			res = max(res, tmp);
			if(__builtin_ctz(u) == max_bit - k) break;
			ll k = u | (u - 1);
			v = (ll)(k + 1) | (((~k & -~k) - 1) >> (__builtin_ctz(u) + 1));
			u = v;
		}
		cout << res << '\n';
	}	
}
