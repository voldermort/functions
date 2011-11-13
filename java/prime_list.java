public static int[] Primelist(int N){
		int[] arr=new int[N];
		for(int q=0;q<N;q++)arr[q]=1;
		arr[0]=arr[1]=0;
		for(int i=2;i<N;i++)
			{
				if(arr[i]==1){
					for(int j=i+i;j<N;j+=i)arr[j]=0;
				}
			}
		return arr;
	}
