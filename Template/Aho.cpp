const int mxN = 1e6 + 5;
int to[mxN][26], sl[mxN], term[mxN], d[mxN][26], de[mxN];
int cur = 0;
 
void add_string(string &s){
	int u = 0;
	for(char c: s){
		if(!to[u][c - 'a'])
			to[u][c - 'a'] = ++cur;
		u = to[u][c - 'a'];
	}	
	term[u] = u;
}
 
void push_sl(){
	queue<int> q;
	q.push(0);
	while(q.size()){
		int u = q.front(); q.pop();
		for(int i = 0; i < 26; ++i){
			int v = to[u][i];
			if(v){
				sl[v] = d[sl[u]][i];
				if(!term[v])
					term[v] = term[sl[v]];
				de[v] = de[u] + 1;	
				d[u][i] = v;
				q.push(v);
			}else
				d[u][i] = d[sl[u]][i];	
 
		}
	}	
}
