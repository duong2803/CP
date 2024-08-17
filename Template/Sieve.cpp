const int mxN = 1e6 + 5;
int sieve[mxN] = {};

void init(){
	for(int i = 2; i * i < mxN; ++i){
		if(!sieve[i])
			for(int j = i * i; j < mxN; j += i)
				sieve[j] = i;
	}	
	for(int i = 2; i < mxN; ++i)
		if(!sieve[i]) sieve[i] = i;
}
