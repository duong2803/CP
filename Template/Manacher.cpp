class Manacher{
private:
	std::vector<int> d_odd, d_even;
public:
	Manacher(const std::string &s) {
		int n = s.size();
		d_odd.resize(n);
		d_even.resize(n);
		
		std::string t = "";
		for(int i = 0; i < n; ++i){
			t += "#";
			t += s[i];
		}	
		t += "#";	
		std::vector<int> d = manacher_odd(t);
		for(int i = 0; i < n; ++i)
			d_odd[i] = d[i * 2 + 1] >> 1, d_even[i] = d[i * 2 + 2] - 1 >> 1;
	}

	std::vector<int> manacher_odd(const std::string& s){
		int l = 0, r = -1;
		int n = s.size();
		std::vector<int> d(n);
		for(int i = 0; i < n; ++i){
			if(r + l - i >= 0)
				d[i] = std::max(0, std::min(r - i, d[r + l - i]));
			while(i + d[i] < n && i - d[i] >= 0 && s[i + d[i]] == s[i - d[i]])
				++d[i];
			if(i + d[i] > r)
				l = i - d[i], r = i + d[i];
		}
		return d;
	}

	bool check(int l, int r){
		int m = l + r >> 1;
		if(r - l + 1 & 1)
			return m - d_odd[m] < l;
		return m - d_even[m] < l;
	} 

	std::vector<int> get_odd(){
		return d_odd;
	}

	std::vector<int> get_even(){
		return d_even;
	}
};
