// https://cses.fi/problemset/task/1647
// Range minimum query using Sparse Table
// Time complexity: O(q) ( O(1) for each query)
#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int> a;
vector<vector<int>> dp;
int P;

void bld(){

	dp.resize(P + 1);
	for(int i = 0; i < n; ++i){
		dp[0].push_back(a[i]);
	}
	for(int i = 1; i <= P; ++i){
		dp[i].resize(n - (1 << i) + 1);
		for(int j = 0; j < n - (1 << i) + 1; ++j){
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
		}	
	}

}

int qry(int l, int r){
	if(l == r) return a[l];
	int p = (int) log2(r - l);
	int k = (1 << p);
	return min(dp[p][l], dp[p][r - k + 1]);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> q;
	a.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	P = (int) log2(n);
	bld();

	while(q--){
		int l, r;
		cin >> l >> r;
		cout << qry(l - 1, r - 1) << '\n';
	}
	return 0;
}
