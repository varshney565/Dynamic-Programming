#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dfs(int i,vector<int> &friends){
	if(i == 0) return {{}};
	if(i == 1) return {{{friends[i]}}};
	//single { {} , {} , {} }
	//now just push the ith friend in each answer
	vector<vector<vector<int>>> ans;
	auto smallAns = dfs(i-1,friends);
	for(auto &x : smallAns){
		x.push_back({friends[i]});
		ans.push_back(x);
	}
	//paired
	for(int j = i - 1 ; j >= 1 ; j--){
		swap(friends[j],friends[i-1]);
		auto smallAns2 = dfs(i-2,friends);
		for(auto &x : smallAns2){
			x.push_back({friends[i],friends[i-1]});
			ans.push_back(x);
		}
		swap(friends[j],friends[i-1]);
	}
	return ans;
};

vector<vector<vector<int>>> friendPairing(int n){
	vector<int> friends(n+1);
	iota(friends.begin(),friends.end(),0);
	return dfs(n,friends);
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("./../IO/input.txt","r",stdin);
        freopen("./../IO/output.txt","w",stdout);
        freopen("./../IO/error.txt", "w", stderr);
    #endif
	int n;cin>>n;
	auto ans = friendPairing(n);
	//{	{{},{}} , {{},{}} , {{},{}} , {{},{},{}} 	}
	for(auto x : ans){
		for(auto i : x){
			cout<<"[";
			for(auto j : i){
				cout<<j<<" ";
			}
			cout<<"]  ";
		}
		cout<<"\n";
	}
}