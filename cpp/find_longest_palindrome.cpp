int find_longest_palindrome(string str){
	int strLength=str.length();
	vector<int> arr;
	int i=0,palLength=0;
	while(i<strLength){
		while(i>palLength&&i<strLength){
			if(str[i-palLength-1]==str[i])palLength+=2,i+=1;
			else break;
		}
		arr.push_back(palLength);
		int s = arr.size() - 2;
		int e = s - palLength;
		bool found = false;
		for (int j = s; j > e; j--) {
			int d = j - e - 1;
			if (arr[j] == d) {
				palLength = d;
				found = true;
			break;
			}
			arr.push_back(min(d,arr[j]));
			}
		if (!found) {
			i += 1;
			palLength = 1;
		}
	}
	arr.push_back(palLength);
	int ret = 0;
	for (int q = 0; q < (int)arr.size(); q++) {
		if (ret < arr[q]) {
			ret = arr[q];
		}
	}
	return ret;
}
