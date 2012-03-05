#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class edge{
	public:
	int from,to,weight;
	edge(int f,int t,int w){from=f;to=t;weight=w;}
	bool operator < (const edge& e)const{
		return weight>e.weight;
	}
};

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

int kruskal(priority_queue<edge> pq,int N){
	UF uf(N);
	int total=0;
	int count=0;
	while(!pq.empty()&&count!=N-1){
		edge e=pq.top();pq.pop();
		if(!uf.connected(e.from,e.to)){
			
			total+=e.weight;
			count++;
			uf.uni(e.from,e.to);
		}
	}
	return total;
}






int main(){
	priority_queue<edge> pq;
	pq.push(edge(0,1,7));
	pq.push(edge(0,3,5));
	pq.push(edge(1,2,8));
	pq.push(edge(1,4,7));
	pq.push(edge(1,3,9));
	pq.push(edge(2,4,5));
	pq.push(edge(3,4,15));
	pq.push(edge(3,5,6));
	pq.push(edge(4,5,8));
	pq.push(edge(4,6,9));
	pq.push(edge(5,6,11));
	
	cout<<kruskal(pq,7);
}
