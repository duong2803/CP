template<int P>
struct Node {
	Node operator+=(const Node &other) { 

		// Declare combine function here
		return *this;
	}
};

template<int P>
Node<P> operator+(const Node<P> &node1, const Node<P> &node2) { return Node<P>(node1) += node2;}

template<typename T>
struct Segtree {
	int n;
	T *st;
	Segtree(int n) : n(n) { st = new T[2 * n + 1]; };
	void upd(int idx, T val){
		st[idx += n] = val;
		for (idx >>= 1; idx; idx >>= 1)
			st[idx] = st[idx << 1] + st[idx << 1 | 1];
	}
	T qry(int l, int r){
		T res;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res += st[l++];
			if (r & 1) res += st[--r];
		}
		return res;
	}
};
