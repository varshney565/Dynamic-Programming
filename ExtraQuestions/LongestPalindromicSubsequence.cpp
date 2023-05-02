#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int lps(string s,int i,int j){
	if(i == j) return dp[i][j] = 1;
	if(i > j) return dp[i][j] = 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(s[i] == s[j]) return dp[i][j] = 2+lps(s,i+1,j-1);
	return dp[i][j] = max(lps(s,i+1,j),lps(s,i,j-1));
}

int lps_tab(string s){
	for(int i = s.size()-1 ; i >= 0 ; i--){
		for(int j = 0 ; j < s.size() ; j++){
			if(i == j) {
				dp[i][j] = 1;
				continue;
			}
			if(i > j){
				dp[i][j] = 0;
				continue;
			}
			if(s[i] == s[j]) dp[i][j] = 2+dp[i+1][j-1];
			else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
		}
	}
	return dp[0][s.size()-1];
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("./../IO/input.txt","r",stdin);
        freopen("./../IO/output.txt","w",stdout);
        freopen("./../IO/error.txt", "w", stderr);
    #endif
	string s;cin>>s;
	int n = s.size();
	dp.resize(n,vector<int>(n,-1));
	cout<<lps_tab(s)<<"\n";
	return 0;
}