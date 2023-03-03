// https://codeforces.com/contest/1788/problem/E
// Sum Over Zero
// Using coordinate compression to fit the size of segment tree
// Time complexity: O(nlog(n))

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5 + 5;
int st[1 << 19];

void upd(int i, int k, int l = 0, int r = mxN, int idx = 0){
	if(l == r){
		st[idx] = max(st[idx], k);
		return;
	}
	int m = l + r >> 1;
	if(i <= m)
		upd(i, k, l, m, idx * 2 + 1);
	else
		upd(i, k, m + 1, r, idx * 2 + 2);
	st[idx] = max(st[idx * 2 + 1], st[idx * 2 + 2]);
}

int qry(int k, int l = 0, int r = mxN, int idx = 0){
	if(l > k || r < 0) return INT_MIN;
	if(l >= 0 && r <= k) return st[idx];
	int m = l + r >> 1;
	return max(qry(k, l, m, idx * 2 + 1), qry(k, m + 1, r, idx * 2 + 2));
}

vector<int> compress(vector<ll> a){
	int n = a.size();
	vector<pair<ll,int>> pairs(n);
	for(int i = 0; i < n; ++i)
		pairs[i] = {a[i], i};
	sort(pairs.begin(), pairs.end());
	int nxt = 0;
	vector<int> res(n);
	for(int i = 0; i < n; ++i){
		if(i > 0 && pairs[i - 1].first != pairs[i].first) ++nxt;
		res[pairs[i].second] = nxt;	
	}
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	fill(begin(st), end(st), -999999);
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<ll> s(n + 1);
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	vector<int> cp = compress(s);
	vector<int> dp(n + 1);
	upd(cp[0], 0);
	for(int i = 1; i <= n; ++i){
		int tmp = qry(cp[i]);
		if(tmp == -999999)
			dp[i] = dp[i - 1];
		else
			dp[i] = max(dp[i - 1], tmp + i);
		upd(cp[i], dp[i] - i);
	}
	cout << dp[n];
	return 0;
}
