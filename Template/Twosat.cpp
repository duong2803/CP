struct TwoSat{
	vector<vector<int>> adj;
	vector<int> comp, low, tin;
	vector<bool> visited;
	stack<int> st;
	int timer = 0, cur = 0;
	int n;
	vector<int> res;
	TwoSat(int n) : n(n) {
		adj.resize(n * 2 + 2);
		comp.resize(n * 2 + 2);
		low.resize(n * 2 + 2);
		tin.resize(n * 2 + 2);
		visited.resize(n * 2 + 2);
		res.resize(n + 1);
	}
 
	void dfs(int u){
		low[u] = tin[u] = ++timer;
		st.push(u);	

		for(int v: adj[u]){
			if(visited[v]) continue;
			if(!low[v]){
				dfs(v);
				low[u] = min(low[u], low[v]);
			}else
				low[u] = min(low[u], tin[v]);
		}

		if(low[u] == tin[u]){
			++cur;
			int v;
			do{
				v = st.top(); st.pop();
				visited[v] = true;
				comp[v] = cur;
			}while(v != u);
		}
	}	

	void add_clause(int u, bool vu, int v, bool vy){
		int x = u << 1;	
		int nx = x | 1;
 
		int y = v << 1;	
		int ny = y | 1;
 
		if(!vu) swap(x, nx);
		if(!vy) swap(y, ny);
 
		adj[nx].push_back(y);
		adj[ny].push_back(x);
	}
 
	bool solve(){
		for(int i = 2; i <= ((n << 1) | 1); ++i)
			if(!low[i])
				dfs(i);
 
		for(int i = 2; i <= (n << 1); i += 2){
			if(comp[i] == comp[i | 1])
				return false;
			res[i >> 1] = comp[i] < comp[i | 1];
		}
		return true;
	}
	
	vector<int> get_res(){
		return this->res;
	}
};

