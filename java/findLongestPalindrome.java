 public static int fastFindPalindrome(String str) {

        int strLength = str.length();
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int i = 0;
        int palLength = 0;
        while (i < strLength) {

            while ((i > palLength&&i<strLength)){
                if ((str.charAt(i - palLength - 1) == str.charAt(i))) {
                palLength += 2;
                i += 1;
                }
                else break;
            }

            arr.add(new Integer(palLength));

            int s = arr.size() - 2;
            int e = s - palLength;

            boolean found = false;
            for (int j = s; j > e; j--) {
                int d = j - e - 1;

                if (((Integer) arr.get(j)).intValue() == d) {
                    palLength = d;
                    found = true;
                    break;
                }
                arr.add(new Integer(Math.min(d, ((Integer) arr.get(j)).intValue())));
            }
            if (!found) {

                i += 1;
                palLength = 1;
            }
        }
        arr.add(new Integer(palLength));

        int ret = 0;
        for (int q = 0; q < arr.size(); q++) {
            if (ret < arr.get(q)) {
                ret = arr.get(q);
            }
        }
        return ret;
    }
