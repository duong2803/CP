#include<iostream>
#include<chrono>
#include<random>
#include<set>
using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
	return uniform_int_distribution<long long>(l, h)(rng);
}


signed main(){

	freopen("test_case.txt", "w", stdout);
	
	int file = 10;
	for(int f = 0; f < file; ++f){
		string file_name = "test" + to_string(f);
		freopen(file_name.c_str(), "w", stdout);
	}

	return 0;
}


