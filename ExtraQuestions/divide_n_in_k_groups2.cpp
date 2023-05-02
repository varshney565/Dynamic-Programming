//https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<vector<int>>> solve(int n,int k){
	//BASE CASE
	if(k == 1) {
		vector<int> t;
		for(int i = n ; i >= 1 ; i--) t.push_back(i);
		return {{t}};
	}
	if(n == k){
		vector<vector<int>> t;
		for(int i = n ; i >= 1 ; i--){
			t.push_back({i});
		}
		return {t};
	}

	//RECURSIVE CALL
	vector<vector<vector<int>>> ans;
	//1 : new gp
	auto s1 = solve(n-1,k-1);
	for(auto &x : s1){
		x.push_back({n});
		ans.push_back(x);
	}
	//2 : existing gp
	auto s2 = solve(n-1,k);
	for(int i = 0 ; i < s2.size() ; i++){
		for(int j = 0 ; j < s2[i].size() ; j++){
			vector<vector<int>> t = s2[i];
			t[j].push_back(n);
			ans.push_back(t);
		}
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("./../IO/input.txt","r",stdin);
        freopen("./../IO/output.txt","w",stdout);
        freopen("./../IO/error.txt", "w", stderr);
    #endif
	cin>>n>>k;
	
	auto ans = solve(n,k);
	for(auto x : ans){
		cout<<"[";
		for(auto y : x){
			cout<<"[";
			for(auto z : y){
				cout<<z<<" ";
			}
			cout<<"] ";
		}
		cout<<"]\n";
	}
	return 0;
}