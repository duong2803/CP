struct FlowEdge{
	int u, v;
	long long cap;
	FlowEdge(int u, int v, long long cap) 
		: u(u), v(v), cap(cap) {}
};

struct Dinic{
	const long long inf = 1e18;
	vector<vector<ll>> adj;
	vector<FlowEdge> edges;
	int n, m = 0;
	int s, t;
	vector<int> level, nxt;

	Dinic(int n, int s, int t) : n(n), s(s), t(t){
		adj.resize(n);	
		level.resize(n);
		nxt.resize(n);
	}

	void add_edge(int u, int v, long long cap){
		edges.emplace_back(u, v, cap);
		edges.emplace_back(v, u, 0);
		adj[u].push_back(m++);
		adj[v].push_back(m++);
	}

	bool bfs(){
		queue<int> q;
		q.push(s);
		while(q.size()){
			int u = q.front(); q.pop();
			for(int id: adj[u]){
				if(level[edges[id].v] == -1 && edges[id].cap > 0){
					level[edges[id].v] = level[u] + 1;
					q.push(edges[id].v);
				}
			}	
		}
		return level[t] != -1;
	}

	long long dfs(int u, long long flow){
		if(flow == 0) return 0;
		if(u == t) return flow;
		for(int &cid = nxt[u]; cid < (int) adj[u].size(); cid++){
			int id = adj[u][cid];
			if(edges[id].cap > 0 && level[edges[id].v] == level[u] + 1){
				long long bottle_neck = dfs(edges[id].v, min(flow, edges[id].cap));
				if(bottle_neck > 0){
					edges[id].cap -= bottle_neck;
					edges[id ^ 1].cap += bottle_neck;
					return bottle_neck;
				}
			}
		}	
		return 0;
	}

	long long max_flow(){
		long long res = 0;
		while(true){
			for(int i = 0; i < n; ++i)
				level[i] = -1;
			level[s] = 0;
			if(!bfs()) break;
			for(int i = 0; i < n; ++i)
				nxt[i] = 0;
			while(long long mx = dfs(s, inf)){
				res += mx;
			}
		}
		return res;
	}
};
