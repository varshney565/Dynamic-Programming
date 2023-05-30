#include<bits/stdc++.h>
using namespace std;

string lps(string s){
	int n = s.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int gap = 1 ; gap <= n ; gap++){
		int i = 0;
		int j = i+gap-1;
		while(j < n){
			if(gap == 1){
				dp[i][j] = 1;
			}else if(gap == 2){
				dp[i][j] = ((s[i] == s[j]) ? 2 : 1);
			}else{
				dp[i][j] = ((s[i] == s[j]) ? 2 + dp[i+1][j-1] : 1 + max(dp[i+1][j],dp[i][j-1]));
			}
		}
	}

	function<string(int,int)> go = [&](int i,int j){
		if(i > j) return "";
		if(i == j) return s[i];
		if(s[i] == s[j]) return s[i] + go(i+1,j-1) + s[j];
		if(dp[i+1][j] > dp[i][j-1]) return go(i+1,j);
		return go(i,j-1);
	}
	
	return go(0,n-1);
}

int main(){
	string s;
	cin>>s;
	return 0;
}