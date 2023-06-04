#include<bits/stdc++.h>
using namespace std;

/**
 * 
 * */


int permutations(vector<int> &v,int n,int target,vector<int> &dp){
	if(dp[target] != -1) return dp[target];
	if(target == 0) return dp[target] = 1;
	int ans = 0;
	for(int i = n - 1 ; i >= 0 ; i--){
		if(target-v[i] >= 0)
			ans += permutations(v,n,target-v[i],dp);
	}
	return dp[target] = ans;
}

int permutations_tab(vector<int> &v,int n,int T){
	vector<int> dp(T+1,0);
	for(int target = 0 ; target <= T ; target++){
		if(target == 0) {
			dp[target] = 1;
			continue;
		}
		int ans = 0;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(target-v[i] >= 0)
				ans += dp[target-v[i]];
		}
		dp[target] = ans;
	}
	return dp[T];
}

int combinations(vector<int> &v,int n,int target,vector<vector<int>> &dp){
	if(target == 0) return dp[n][target] = 1;
	if(dp[n][target] != -1) return dp[n][target];
	int count = 0;

	//take the last element.
	if(target-v[n-1] >= 0)
		count += combinations(v,n,target-v[n-1],dp);

	//ignore the last element.
	if(n > 1)
		count += combinations(v,n-1,target,dp);
	return dp[n][target] = count;
}

int combinations_tab(vector<int> &v,int N,int T){
	vector<vector<int>> dp(N+1,vector<int>(T+1,0));
	for(int n = 1 ; n <= N ; n++){
		for(int target = 0 ; target <= T ; target++){
			if(target == 0) {
				dp[n][target] = 1;
				continue;
			}
			int count = 0;
			if(target-v[n-1] >= 0)
				count += dp[n][target-v[n-1]];
			if(n > 1)
				count += dp[n-1][target];
			dp[n][target] = count;
		}
	}
	return dp[N][T];
}


/**
 * As answer of ith state is only dependent on the current state and the previous state.
 * 
 * As,
 * dp[n][target] = dp[n-1][target] + dp[n][target-v[i]]
 * 
 * so dp[target] += dp[target-v[i]];
 * 
 * */

int combinations_opti(vector<int> &v,int N,int T){
	vector<int> dp(T+1,0);
	dp[0] = 1;
	for(int n = 1 ; n <= N ; n++){
		for(int target = n ; target <= T ; target++){
			if(target-v[n-1] >= 0)
				dp[target] += dp[target-v[n-1]];
		}
	}
	return dp[T];
}

int main(){
	int n;cin>>n;
	int target;cin>>target;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++) cin>>v[i];
	int ans = combinations_opti(v,n,target);
	cout<<ans<<"\n";
}