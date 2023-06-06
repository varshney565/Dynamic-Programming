/**
 * 
 * find all sets such that sum of all the elements is equal to target and we can take 
 * a element no more than one time.
 * 
 * */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> v;

vector<vector<int>> DoIt(int n,int target){
	if(target == 0) return {{}};
	if(n == 0) return {};
	//take
	vector<vector<int>> ans;
	if(target-v[n-1] >= 0 && dp[n-1][target-v[n-1]] == 1){
		auto smallAns = DoIt(n-1,target-v[n-1]);
		for(auto &x : smallAns){
			x.push_back(v[n-1]);
			ans.push_back(x);
		}
	}
	//ignore
	if(dp[n-1][target] == 1){
		auto smallAns = DoIt(n-1,target);
		for(auto &x : smallAns){
			ans.push_back(x);
		}
	}
	return ans;
}

vector<vector<int>> getAll(int n,int tar){
	function<int(int,int)> go = [&](int n,int target){
		if(target == 0) return dp[n][target] = 1;
		if(n == 0) return dp[n][target] = 0;
		if(dp[n][target] != -1) return dp[n][target];
		//take
		bool res = false;
		if(target-v[n-1] >= 0)
			res = go(n-1,target-v[n-1]);
		//ignore
		res = go(n-1,target) || res;
		return dp[n][target] = res ? 1 : 0;
	};

	go(n,tar);
	return DoIt(n,tar);
}

int main(){
	int n;cin>>n;
	int tar;cin>>tar;
	v.resize(n);
	for(int i = 0 ; i < n ; i++) cin>>v[i];
	dp.resize(n+1,vector<int>(tar+1,-1));
	auto ans = getAll(n,tar);
	cout<<"[\n";
	for(auto x : ans){
		cout<<"  [";
		for(auto y : x){
			cout<<y<<",";
		}
		cout<<"]\n";
	}
	cout<<"]\n";
	return 0;
}