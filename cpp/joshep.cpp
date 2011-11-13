int Joseph ( int n, int k )  { 
	int res =  0 ; 
	for  ( int I = 1 ; I <= n ;  ++I ) 
		res =  ( res + k )  % I ; 
	return res +  1 ; 
}
