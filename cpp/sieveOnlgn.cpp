vector<int> Primelist(int N){
		vector<int> rr(N,1);
		arr[0]=arr[1]=0;
		for(int i=2;i<N;i++)
			{
				if(arr[i]==1){
					for(int j=i+i;j<N;j+=i)arr[j]=0;
				}
			}
		return arr;
}
