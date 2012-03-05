const int INF = 1000 * 1000 * 1000;
 
class MaxFlow
{
public:
	vector<vector<int> > g;
	vector<bool> used;
	int n;
 
	bool is_path(int s, int t, int c)
	{
		if(s == t) return true;
		if(used[s]) return false;
		used[s] = true;
		for(int i = 0; i < n; i++)
			if(g[s][i] >= c && is_path(i, t, c))
			{
				g[s][i]-=c;
				g[i][s]+=c;
				return true;
			}
		return false;
	}
	 
	int max_flow(int s, int t, vector<vector<int> > &_g)//& is used for changing _g in up-level min_cut function
	{
		g = _g;
		n = g.size();
		used = vector<bool> (n, false);
 
		int flow = 0, c = INF;
		while(c > 0)
		{
			if(is_path(s, t, c))
				flow += c;
			else
				c /= 2;
			fill(used.begin(), used.end(), false);
		}
		return flow;
	}
};
 
class MinCutMaxFlow
{
public:
	void push_component(const vector<vector<int> > &g, vector<int> &comp)
	{
		//using dfs with stack
		int n = g.size();
		stack<int> st;
		vector<bool> used(n);
		st.push(0);
		comp.push_back(0);
		used[0] = true;
		while(!st.empty())
		{
			int top = st.top(); st.pop();
			for(int i = 0; i < n; i++)
				if(g[top][i] && !used[i])
				{
					used[i] = true;
					st.push(i);
					comp.push_back(i);
				}
		}
 
		return;
	}
 
	pair<int, vector<int> > min_cut(const vector<vector<int> > &g)
	{ 
            MaxFlow obj;
		pair<int, vector<int> > res(INF, vector<int>());//res.first is total weight of deleted edges
							        //res.second is vertices from one of components(sorted);
		int n = g.size();
		for(int i = 1; i < n; i++)
		{
			//searching max_flow from vertex 0 to vertex i
			vector<vector<int> > _g(g);
			int weight = obj.max_flow(0, i, _g);
			if(weight < res.first)
			{
				res.first = weight;
				res.second.clear();
				push_component(_g, res.second);
			}
		}
		return res;
	}
};
