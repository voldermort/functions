class Uf
{
  public:
	int* id ;
	int* sz;
	int count;
	Uf(int n){
		id=new int[n];
		sz=new int[n];
		count =0;
		for(int i=0;i<n;i++){
			id[i]=i;
			sz[i]=1;
		}			
	}
	int find(int p){
		while(p!=id[p])
			p=id[p];
		return p;
	}

	bool connected(int i,int j){		
		return find(i)==find(j);	
	}
	
	void uni(int p,int q){
		int i=find(p);
		int j=find(q);
		if(i==j)return ;
		
		if(sz[i]>sz[j]){id[j]=i;sz[j]+=sz[i];}
		else {id[i]=j;sz[j]+=sz[i];}
		count--;
	}
		
	
};
