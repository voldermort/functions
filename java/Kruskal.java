/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package kruskal;

import java.util.*;

class UF {
    private int[] id;    
    private int[] sz;    
    private int count;   

    public UF(int N) {
        count = N;
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    public int find(int p) {
        while (p != id[p])
            p = id[p];
        return p;
    }

    public int count() {
        return count;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public void union(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;

        if   (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else                 { id[j] = i; sz[i] += sz[j]; }
        count--;
    }


}



class Edge implements Comparable<Edge>{
	int from;
	int to;
	int weight;
	public Edge(int f,int t,int w){
		from=f;
		to=t;
		weight=w;
	}
	public int compareTo(Edge o2){
	if (weight>o2.weight)return 1;
	else return -1;
	}

}
public class Kruskal{
    
    
static int kruskal(PriorityQueue<Edge> pq,int N){
    UF uf=new UF(N);
    int total=0;
    int count=0;
    while(!pq.isEmpty()&&count!==N-1){
        Edge e=pq.poll();
        if(!uf.connected(e.from, e.to)){
            total+=e.weight;
            uf.union(e.from, e.to);
        }
    }

    return total;
}





	public static void main(String[] args){
            Scanner in=new Scanner(System.in);
            PriorityQueue<Edge> pq=new PriorityQueue<Edge>();
                int N=in.nextInt();
                int M=in.nextInt();
                for(int i=0;i<M;i++){
                    int x=in.nextInt();
                    int y=in.nextInt();
                    int z=in.nextInt();
                    pq.add(new Edge(x,y,z));
                }
                System.out.println(kruskal(pq,N));
	}
}
