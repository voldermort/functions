class SuffixArray {
    private String[] suffixes;
    private  int N;

    public SuffixArray(String s) {
        N = s.length();
        suffixes = new String[N];
        for (int i = 0; i < N; i++)
            suffixes[i] = s.substring(i);
        Arrays.sort(suffixes);
    }
	    public int length() { return N; }

    // index of ith sorted suffix
    public int index(int i) { return N - suffixes[i].length(); }

    // ith sorted suffix
    public String select(int i) { return suffixes[i]; }
	
    private static int lcp(String s, String t) {
        int N = Math.min(s.length(), t.length());
        for (int i = 0; i < N; i++)
            if (s.charAt(i) != t.charAt(i)) return i;
        return N;
    }

	 public int lcp(int i) {
        return lcp(suffixes[i], suffixes[i-1]);
    }
    
    public int lcp(int i, int j) {
        return lcp(suffixes[i], suffixes[j]);
    }


}
