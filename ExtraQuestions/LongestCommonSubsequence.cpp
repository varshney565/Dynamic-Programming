#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int lcs(string &a,string &b,int n,int m){
    if(n == 0 || m == 0) return dp[n][m] = 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(a[n-1] == b[m-1]) return dp[n][m] = 1+lcs(a,b,n-1,m-1);
    return dp[n][m] = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
}

int lcs_tab(string &a,string &b){
	int N = a.size();
    int M = b.size();
    for(int n = 0 ; n <= N ; n++){
        for(int m = 0 ; m <= M ; m++){
            if(n == 0 || m == 0) {
                dp[n][m] = 0;
                continue;
            }
            if(a[n-1] == b[m-1]) dp[n][m] = 1+dp[n-1][m-1];
            else dp[n][m] = max(dp[n-1][m],dp[n][m-1]);
        }
    }
    return dp[N][M];
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
	dp.resize(n+1,vector<int>(m+1,-1));
	cout<<lcs(a,b,n,m)<<"\n";
	return 0;
}