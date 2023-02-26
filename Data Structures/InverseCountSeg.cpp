#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 4e5 + 5;
ll st[mxN];
int n;
void compress(vector<int>& a){
	int n = a.size();
	vector<pair<int, int>> pairs(n);
	for(int i = 0; i < n; ++i) {
		pairs[i] = {a[i], i};
	}
	sort(pairs.begin(), pairs.end());
	int nxt = 0;
	for(int i = 0; i < n; ++i) {
		if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
		a[pairs[i].second] = nxt;		
	}	
}

void upd(int k, int l = 0, int r = 1e5 + 5, int idx = 0){
	if(l == r){
		st[idx]++;
		return;
	}
	int m = l + r >> 1;
	if(k <= m)
		upd(k, l, m, idx * 2 + 1);
	else
		upd(k, m + 1, r, idx * 2 + 2);
	st[idx] = st[idx * 2 + 1] + st[idx * 2 + 2];
}

ll qry(int k, int l = 0, int r = 1e5 + 5, int idx = 0){
	if(l > k) return 0;
	if(l >= 0 && r <= k) return st[idx];
	int m = l + r >> 1;
	return qry(k, l, m, idx * 2 + 1) + qry(k, m + 1, r, idx * 2 + 2);
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		memset(st, 0, sizeof(st));
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		compress(a);
		ll cnt = 0;
		for(int i = n - 1; i >= 0; --i){
			if(a[i] > 0){
				cnt += qry(a[i] - 1);
			}
			upd(a[i]);
		}
		cout << cnt << '\n';
		
	}
	return 0;
}
