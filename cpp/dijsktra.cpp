int dijsktra(vector< vector<pair<int,int> > > &adj ,int from, int to,int n){
	int sz,x,w,cost,at;
	int dist[n];
	for(int i = 0; i < n; ++i) dist[i] =(i != from) << 30;
	dist[from]=0;
	priority_queue < pair< int, int > > q;
	q.push(make_pair(0, from));
	while(!q.empty()){
		pair < int, int > pp = q.top(); q.pop();
		at = pp.second, cost =-pp.first, sz = adj[at].size();
		if(dist[at] < cost) continue;
		if(at == to) break;
		for(int i = 0; i < sz; ++i){
			x = adj[at][i].first, w = adj[at][i].second;
			if(dist[x] > cost + w){
				dist[x]=cost+w;
				q.push(make_pair(-dist[x], x));
			}
		}
	}
	return dist[to];
}
