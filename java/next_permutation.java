public static boolean nextPermutation(int[] a)
{
	int N=a.length;
	int i=N-2;
	for (; i>=0; i--) if (a[i]<a[i+1]) break;
	if (i<0) return false;
		
	for (int j=N-1; j>=i; j--)
	{
		if (a[j]>a[i])
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			break;		
		}
	}
	for (int j=i+1; j<(N+i+1)/2; j++)		//reverse from a[i+1] to a[N-1]
	{
		int temp=a[j];
		a[j]=a[N+i-j];
		a[N+i-j]=temp;
	}
	return true;
}
