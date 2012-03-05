
void gen_primes() 
     { 
       int i,j; 
       for(i=0;i<MAX;i++) primes[i] = 1; 
       for(i=2;i<=(int)sqrt(MAX);i++) 
         if (primes[i]) 
           for(j=i;j*i<MAX;j++) primes[i*j] = 0; 
     } 

int FindSol(int n) 
     { 
       int i,res=0; 
       for(i=2;i<=n/2;i++) 
         if (primes[i] && primes[n-i]) res++; 
       return res; 
     } 
