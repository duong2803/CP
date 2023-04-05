#include<bits/stdc++.h>
using namespace std;

vector<int> Z_arr(string s){
	int n = s.length();
	vector<int> Z(n);	
	int l = 0;
	int r = 0;

	for(int i = 0; i < n; ++i){
		if(i > r){
			r = l = i;
			while(r < n && s[r] == s[r - l]) ++r;
			Z[i] = r - l; --r;
		}else{
			int k = i - l;
			if(Z[k] < r - i + 1) Z[i] = Z[k];
			else{
				l = i;
				while(r < n && s[r] == s[r - l]) ++r;
				Z[i] = r - l; --r;
			}
		}
	}
	return Z;
}

vector<int> KMP(string s){
	int n = s.length();
	vector<int> K(n);
	for(int i = 1; i < n; ++i){
		int j = K[i - 1];
		while(j > 0 && s[i] != s[j])
			j = K[j - 1];
		if(s[i] == s[j])
			++j;
		K[i] = j;
	}
	return K;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> z = Z_arr(s);
	vector<int> kmp = KMP(s);
	for(int i: z)
		cout << i << ' ';
	cout << '\n';
	for(int i : kmp)
		cout << i << ' ';
	cout << '\n';
	return 0;
}
