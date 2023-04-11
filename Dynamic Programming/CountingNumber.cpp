// Source: https://cses.fi/problemset/task/2220/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	ll a, b;
	cin >> a >> b;
	ll res = (a == 0);
	vector<int> n1;
	vector<int> n2;
	while(a){
		n1.push_back(a % 10);
		a /= 10;
	}
	while(b){
		n2.push_back(b % 10);
		b /= 10;
	}
	if(n1.empty()) n1.push_back(0);
	if(n2.empty()) n2.push_back(0);
	int n = max(n1.size(), n2.size());
	while(n1.size() != n) n1.push_back(0);
	while(n2.size() != n) n2.push_back(0);

	n1.push_back(0);
	n2.push_back(0);

	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	ll dp[30][10][2][2][2] = {};
	// dp(n, nth digit, positive, lower, higher)
	
	dp[0][0][0][0][0] = 1;
	for(int i = 0; i < n; ++i){
		for(int digit = 0; digit < 10; ++digit){
			for(int positive = 0; positive < 2; ++positive){
				for(int lower = 0; lower < 2; ++ lower){
					for(int higher = 0; higher < 2; ++higher){
						
						for(int digit2 = 0; digit2 < 10; ++digit2){

							if(positive && digit == digit2) continue;
							if(!positive && digit != 0 && digit == digit2) continue;
							if(!lower && digit2 > n2[i + 1]) continue;
							if(!higher && digit2 < n1[i + 1]) continue;

							int positive2 = positive || digit2 > 0;
							int lower2 = lower || digit2 < n2[i + 1];
							int higher2 = higher || digit2 > n1[i + 1];

							dp[i + 1][digit2][positive2][lower2][higher2] += dp[i][digit][positive][lower][higher];
				
						}

					}
				}
			}
		}
	}
	
	for(int i = 0; i < 10; ++i){
		for(int lower = 0; lower < 2; ++lower){
			for(int higher = 0; higher < 2; ++higher){
				res += dp[n][i][1][lower][higher];
			}
		}
	}
	cout << res << '\n';
    return 0;
}
