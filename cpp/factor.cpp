vector<int> Primelist(int N){
		vector<int> arr(N,1);
		arr[0]=arr[1]=0;
		for(int i=2;i<N;i++)
			{
				if(arr[i]==1){
					for(int j=i+i;j<N;j+=i)arr[j]=0;
				}
			}
		return arr;
}

vector<pair<int,int> >factor(ll a){
	vector<int> pp=Primelist(sqrt(a)+1);
	vector<int> p;
	reps(i,pp){
		if(pp[i])p.pb(i);
	}
	int i=0;
	vector<pair<int,int> > f;
	while(i<sz(p)&&a){
		int t=1;
		while(a%p[i]==0&&a){
			t*=p[i];
			a/=p[i];
		}
		if(t!=1)f.pb(make_pair(p[i],t));
		i++;
	}
	if(a!=1&&a)f.pb(make_pair(a,a));
	return f;
	
}
