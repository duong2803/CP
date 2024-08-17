void compress(std::vector<int> &a){
	int n = a.size();
	std::vector<std::pair<int,int>> b(n);
	for(int i = 0; i < a.size(); ++i)
		b[i] = {a[i], i};
	std::sort(b.begin(), b.end());
	int nxt = 0;
	for(int i = 0; i < n; ++i){
		if(i > 0 && b[i].first != b[i - 1].first) ++nxt;
		a[b[i].second] = nxt;
	}
}
