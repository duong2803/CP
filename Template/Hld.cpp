const int mxN = 2e5;
vector<int> adj[mxN];
int pos[mxN], par[mxN], head[mxN], heavy[mxN], d[mxN];
int id = 0;
int dfs(int u = 0){
	int sz = 1;
	int sz_max = 0;
	for(int v: adj[u]){
		if(par[u] == v) continue;
		par[v] = u, d[v] = d[u] + 1;
		int sz_c = dfs(v);
		sz += sz_c;
		if(sz_c > sz_max)
			sz_max = sz_c, heavy[u] = v;
	}
	return sz;
}
 
void decompose(int u = 0, int h = 0){
	head[u] = h;
	pos[u] = id++;
	if(heavy[u] != -1)
		decompose(heavy[u], h);
 
	for(int v: adj[u]){
		if(par[u] != v && heavy[u] != v)
			decompose(v, v);
	}
}
