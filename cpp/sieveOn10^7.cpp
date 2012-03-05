#include<iostream>
#include<vector>
using namespace std;

vector<long long > Primelist(long long  N){
		vector<long long > arr(N+1,1);
		vector<long long > ret;
		arr[0]=arr[1]=0;
		ret.push_back(2);
		for(long long  i=3;i<N;i+=2)
			{
				if(arr[i]==1){
					ret.push_back(i);
					for(long long  j=i*i;j<N;j+=i)arr[j]=0;
				}
			}
		//return arr;
		return ret;
}


vector<int>	sieve(){
	vector <int> pr;
	int N=87000000;
	vector<int> lp(N,0);
	for (int i = 2; i <N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
	 }
	for (int j = 0; j <(int) pr.size() && pr[j] <= lp[i] && i*pr[j]<N; ++j)
		lp[i * pr[j]] = pr[j];
	} 
	return pr;
}

int main(){
	
	//~ vector<int> v=sieve();
	vector<long long > v=Primelist(87000000);
	cout<<v.size();
	//~ for(int i=0;i<10;i++)cout<<v[i]<<" ";
}
