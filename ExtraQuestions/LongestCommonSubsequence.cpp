#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int lcs(string a,string b,int i,int j){
	if(i < 0 || j < 0) return 0;
	if(a[i] == b[j]) return 1+lcs(i-1,j-1);
	return max(lcs(i-1,j),lcs(i,j-1));
}

int lcs_tab(string s){
	
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("./../IO/input.txt","r",stdin);
        freopen("./../IO/output.txt","w",stdout);
        freopen("./../IO/error.txt", "w", stderr);
    #endif
	string a,b;cin>>a>>b;
	int n = a.size();
	int m = b.size();
	dp.resize(n,vector<int>(m,-1));
	cout<<lcs(a,b,n-1,m-1)<<"\n";
	return 0;
}