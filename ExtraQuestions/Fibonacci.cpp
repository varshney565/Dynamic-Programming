#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &dp){
	for(auto &x : dp) cout<<x<<" ";cout<<"\n";
}

void print(vector<vector<int>> &dp){
	for(auto &x : dp){
		print(x);
	}
}

/**
 * Rules : 
 * 
 * a) Faith
 * b) Recursive Tree
 * c) Recursive Code --> Memoixation
 * d) observation
 * e) Tabulation
 * f) optimization
 * 
 * */

int FIB(int n){
	if(n <= 1) return n;
	int ans = FIB(n-1)+FIB(n-2);
	return ans;
}

int FIB_memo(int n,vector<int> &dp){
	if(n <= 1) return dp[n] = n;
	if(dp[n] != -1) return dp[n];
	return dp[n] = FIB_memo(n-1,dp)+FIB_memo(n-2,dp);
}

int FIB_TAB(int N,vector<int>& dp){
	for(int n = 0 ; n <= N ; n++){
		if(n <= 1) {
			dp[n] = n;
			continue;
		}
		dp[n] = dp[n-1]+dp[n-2];
	}
	return dp[N];
}

int FIB_OPTI(int n){
	int a = 0;
	int b = 1;
	for(int i = 1 ; i <= n ; i++){
		int c = a+b;
		a = b;
		b = c;
	}
	return a;
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("./../IO/input.txt","r",stdin);
        freopen("./../IO/output.txt","w",stdout);
        freopen("./../IO/error.txt", "w", stderr);
    #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	int a1 = FIB(n);
	vector<int> dp(n+1,-1);
	int a2 = FIB_memo(n,dp);
	print(dp);
	/**
	 * Observation : 
	 * 
	 * 0 1 1 2 3 5
	 * 
	 * go from left to right mean o to n.why ???
	 * because i is dependent on i-1 and i-2.
	 * 
	 * */
	cout<<a2<<"\n";
}