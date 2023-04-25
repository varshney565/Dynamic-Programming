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

int boardPath(int n){
	if(n == 0) return 1;
	int ans = 0;
	for(int i = 1 ; i <= 6 ; i++){
		if(n-i >= 0)
			ans += boardPath(n-i);
	}
	return ans;
}

int boardPath_memo(int n,vector<int> &dp){
	if(n == 0) return dp[n] = 1;
	if(dp[n] != -1) return dp[n];
	int ans = 0;
	for(int i = 1 ; i <= 6 ; i++){
		if(n-i >= 0)
			ans += boardPath(n-i);
	}
	return dp[n] = ans;
}

int boardPath_tab(int N,vector<int> &dp){
	for(int n = 0 ; n <= N ; n++){
		if(n == 0) {
			dp[n] = 1;
			continue;
		}
		int ans = 0;
		for(int i = 1 ; i <= 6 ; i++){
			if(n-i >= 0)
				ans += boardPath(n-i);
		}
		dp[n] = ans;
	}
	return dp[N];
}

int boardPath_optimised(int N){
	deque<int> dq;
	int sum = 1;
	for(int n = 0 ; n <= N ; n++){
		if(n == 0){
			dq.push_back(sum);
			continue;
		}
		if(dq.size() <= 6){
			dq.push_back(sum);
		}else{
			sum -= dq.front();
			dq.pop_front();
			dq.push_back(sum);
		}
		sum += dq.back();
	}
	return dq.back();
}

int main(){
	int n;
	cin>>n;
	int ans = boardPath();
	return 0;
}