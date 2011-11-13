


    public static String longestSubstr(String text) {
        
        SuffixArray sa = new SuffixArray(text);

        int N = sa.length();

        String substring = "";
        for (int i = 1; i < N; i++) {
            int length = sa.lcp(i);
            if (length > substring.length())
                substring = sa.select(i).substring(0, length);
        }
        
        return substring;
    }
}
