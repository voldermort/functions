

const int maxn = 100;
 int C [maxn + 1][maxn + 1];
void pas_trinagle(){
 for(int n = 0; n <= maxn; ++n) {
	 C [n] [0] = C [n] [n] = 1;
	 for (int k = 1; k <n; ++k)
		 C [n] [k] = C [n - 1] [k - 1] + C [n - 1] [k];
 } 
}
