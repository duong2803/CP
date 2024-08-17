template<typename T>
struct FenwickTree{
	T* fen;
	int n;
	FenwickTree(int n){
		this->n = n;
		this->fen = new T[n + 1]();
	}
  	~FenwickTree() {
		delete[] fen;
	}
 
	void update(int i, T x){
		for(; i <= n; i += i & -i) 
			fen[i] += x;
	}
 
	T query(int l, int r){
		T res = 0;
		--l;
		for(; l > 0; l -= l & -l) res -= fen[l];
		for(; r > 0; r -= r & -r) res += fen[r];
		return res;
	}
};
