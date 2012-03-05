
class UF{
	public:
	int count;
	int* id;
	int* sz;
	UF(int n){
		count=n;
		id=new int[n];
		sz=new int[n];
		for(int i=0;i<n;i++)
		{
			sz[i]=1;
			id[i]=i;
		}
	}
	
	int find(int p){
		while(p!=id[p])p=id[p];
		return p;
	}
	
	void uni(int p,int q){
		int i = find(p);
		int j = find(q);
		if (i == j) return;
		if   (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
		else                 { id[j] = i; sz[i] += sz[j]; }
		count--;
	}
	
	bool connected(int i,int j){
		int p=find(i);
		int q=find(j);
		return p==q;
		
	}
	 public int count() {
		return count;
	}

};
