#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<cassert>
#include<climits>
using namespace std;

vector<int> longest_incr(const vector<int>&v){
	vector<int> ans(v.size(),0);
	
	for(int i=v.size()-1;i>=0;i--){
		ans[i]=1;
		for(int j=i+1;j<(int)v.size();j++){
			if(v[j]>v[i])if(ans[j]+1>ans[i])ans[i]=ans[j]+1;
		}
	}
	int ret=0;
	for(int j=0;j<(int)ans.size();j++)
		if(ans[j]>ret)ret=ans[j];
	
	vector<int> r;
	
	for(int i=0;i<(int)v.size();i++){
		if(ans[i]==ret){r.push_back(v[i]);}
		if(!ret)break;
	}
	return r;
}
int main(){}
