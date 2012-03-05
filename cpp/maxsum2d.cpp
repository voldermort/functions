
int MaxSum2D(vector< vector<int> > M)
{
    int S=1<<31,k,j,i,t,s;
    int N=M.size();
    
    for (i=0;i<N;i++)
    {
        vector<int>pr(N,0);
        for (j=i;j<N;j++)
        {
            t=0;s=1<<31;
            for (k=0;k<N;k++)
            {
                pr[k]=pr[k]+M[j][k];
                t=t+pr[k];
                s=max(t,s);
                if (t<0)
                   t=0;
            }
            S=max(S,s);
        }
    }
    return S;
}
