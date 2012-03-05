vi fail_fun(string pt){
	int m=sz(pt),mat;
	vi f(m+1,-1);
	repi(i,1,m){
		mat=f[i-1];
		while(mat!=-1&&pt[mat]!=pt[i-1])mat=f[mat];
		f[i]=mat+1;
	}
	return f;
}

vi kmp(string s,string p){
	
	vi ret;
	int sp=0, pp=0,ps=sz(p);
	vi f=fail_fun(p);
	reps(i,s){
		while(pp!=-1&&(pp==ps||p[pp]!=s[sp]))pp=f[pp];
		sp++;
		pp++;
		if(pp==ps)ret.pb(sp-ps);
	}
	return ret;
}
