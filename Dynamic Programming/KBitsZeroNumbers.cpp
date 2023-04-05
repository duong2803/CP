#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	while(cin >> n >> k){
		int dp[50][50][2][2] = {};	
		// dp(n, numberOfBit0, isLower, positive)
		vector<int> bin;
		while(n){
			bin.push_back(n & 1);
			n >>= 1;
		}	
		if(bin.empty()) bin.push_back(0);
		bin.push_back(0);
		reverse(bin.begin(), bin.end());
		n = bin.size() - 1;
		if(k > n){
			cout << 0 << '\n';
			continue;
		}
		dp[0][0][0][0] = 1;	
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <= i; ++j){
				for(int isLower = 0; isLower < 2; ++isLower){
					for(int positive = 0; positive < 2; ++positive){	
						for(int digit = 0; digit <= 1; ++digit){
							if(!isLower && digit > bin[i + 1])
								continue;
							int positive2 = positive || (digit == 1);
							int isLower2 = isLower || (digit < bin[i + 1]);
							int k2 = j + (digit == 0 && positive);

							dp[i + 1][k2][isLower2][positive2] += dp[i][j][isLower][positive];
						}
					}
				}
			}
		}

		int ans = dp[n][k][0][1] + dp[n][k][1][1];
		if(k == 1) ++ans;
		cout << ans << '\n';
	}
	return 0;
}


