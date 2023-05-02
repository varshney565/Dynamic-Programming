//https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<int>> dp;
int solve(int n,int k){
	if(n == k || k == 1) return dp[n][k] = 1;
	if(dp[n][k] != -1) return dp[n][k];
	int ans = 0;
	//saperate gp (n-1,k-1)
	ans += solve(n-1,k-1);
	//combine that element in one of the gp (n-1,k)
	ans += k*solve(n-1,k);
	return dp[n][k] = ans;
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("./../IO/input.txt","r",stdin);
        freopen("./../IO/output.txt","w",stdout);
        freopen("./../IO/error.txt", "w", stderr);
    #endif
	cin>>n>>k;
	dp.resize(n+1,vector<int>(k+1,-1));
	cout<<solve(n,k)<<"\n";
	return 0;
}