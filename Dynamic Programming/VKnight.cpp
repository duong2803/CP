// Source: https://oj.vnoi.info/problem/vknights

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool on_bit(int n, int bit){
	return (n >> (bit - 1)) & 1;
}

bool check1(int a, int b){
	return (on_bit(a, 1) && on_bit(b, 3));
}

bool check2(int a, int b){
	return on_bit(a, 2) && on_bit(b, 1) || on_bit(a, 2) && on_bit(b, 3) || on_bit(a, 1) && on_bit(b, 2) || on_bit(a, 3) && on_bit(b, 2); 
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> Z(n + 1);
	for(int i = 1; i <= n; ++i) cin >> Z[i];

	int dp[201][8][8] = {};
	int C[201][8][8] = {};
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int mask1 = 0; mask1 < 8; ++mask1){
			if(on_bit(mask1, Z[i - 1])) continue;
			for(int mask2 = 0; mask2 < 8; ++mask2){
				if(on_bit(mask2, Z[i])) continue;
				if(check1(mask1, mask2) || check1(mask2, mask1)) continue;
				if(i == 1){
					dp[i][mask1][mask2] = __builtin_popcount(mask2);
					if(mask1 == 0)
						C[i][mask1][mask2] = 1;
					continue;
				}
				for(int pre_mask = 0; pre_mask < 8; ++pre_mask){
					if(i == 2 && pre_mask > 0) continue;
					if(on_bit(pre_mask, Z[i - 2])) continue;
					if(check1(mask1, pre_mask) || check1(pre_mask, mask1)) continue;
					if(check2(pre_mask, mask2) || check2(mask2, pre_mask)) continue;
					int tmp = dp[i - 1][pre_mask][mask1] + __builtin_popcount(mask2);
					if(dp[i][mask1][mask2] < tmp){
						dp[i][mask1][mask2] = tmp;
						C[i][mask1][mask2] = C[i - 1][pre_mask][mask1];
					
					}else if(dp[i][mask1][mask2] == tmp)
						C[i][mask1][mask2] += C[i - 1][pre_mask][mask1];
				}
			}
		}
	}	

	int ways = 0;
	
	for(int mask1 = 0; mask1 < 8; ++mask1){
		for(int mask2 = 0; mask2 < 8; ++mask2){
			if(ans < dp[n][mask1][mask2]){
				ans = dp[n][mask1][mask2];
				ways = C[n][mask1][mask2];
			}else if(ans == dp[n][mask1][mask2])
				ways += C[n][mask1][mask2];
		}
	}
	cout << ans << ' ' << ways << '\n';
	return 0;
}
