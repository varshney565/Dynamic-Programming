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

int boardPath(int n,vector<int> &moves){
	if(n == 0) return 1;
	int ans = 0;
	for(int i = 0 ; i < moves.size() ; i++){
		if(n-moves[i] >= 0)
			ans += boardPath(n-moves[i],moves);
	}
	return ans;
}

int boardPath_memo(int n,vector<int> &moves,vector<int>&dp){
	if(n == 0) return dp[n] = 1;
	if(dp[n] != -1) return dp[n];
	int ans = 0;
	for(int i = 0 ; i < moves.size() ; i++){
		if(n-moves[i] >= 0){
			ans += boardPath(n-moves[i],moves,dp);
		}
	}
	return dp[n] = ans;
}


int boardPath_tab(int N,vector<int> &moves,vector<int>&dp){
	for(int n = 0 ; n <= N ; n++){
		if(n == 0) {
			dp[n] = 1;
			continue;
		}
		int ans = 0;
		for(int i = 0 ; i < moves.size() ; i++){
			if(n-moves[i] >= 0){
				ans += dp[n-moves[i]];
			}
		}
		dp[n] = ans;
	}
	return dp[N];
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> moves;
	for(int i = 0 ; i < m ; i++) cin>>moves[i];
	vector<int> dp(n+1,-1);
	int ans = boardPath_memo(n,moves,dp);
	return 0;
}