/**
 * Question is we are given a 2D matrix and we have to reach from (0,0) to (n-1,m-1).
 * 
 * direction allowed :   R(right),D(down),RD(right diagonal)
 * 
 * jump allowed is INF
 * 
 * */

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

int dir[][2] = {{0,-1},{-1,-1},{-1,0}};
int n,m;

int maze_path(int x,int y){
	if(x == 0 && y == 0) return 1;
	int ans = 0;
	for(int i = 0 ; i < 3 ; i++){
		int newx = x;
		int newy = y;
		int dx = dir[i][0];
		int dy = dir[i][1];
		while(newx+dx >= 0 && newx+dx < n && newy+dy >= 0 && newy+dy < m){
			newx += dx;
			newy += dy;
			ans += maze_path(newx,newy);
		}
	}
	return ans;
}

int maze_path_memo(int x,int y,vector<vector<int>>&dp){
	if(x == 0 && y == 0) return dp[x][y] = 1;
	if(dp[x][y] != -1) return dp[x][y];
	int ans = 0;
	for(int i = 0 ; i < 3 ; i++){
		int newx = x;
		int newy = y;
		int dx = dir[i][0];
		int dy = dir[i][1];
		while(newx+dx >= 0 && newx+dx < n && newy+dy >= 0 && newy+dy < m){
			newx += dx;
			newy += dy;
			ans += maze_path_memo(newx,newy,dp);
		}
	}
	return dp[x][y] = ans;
}

int maze_path_tab(int X,int Y,vector<vector<int>>&dp){
	for(int x = 0 ; x <= X ; x++){
		for(int y = 0 ; y <= Y ; y++){
			if(x == 0 && y == 0){
				dp[x][y] = 1;
				continue;
			}

			int ans = 0;
			for(int i = 0 ; i < 3 ; i++){
				int newx = x;
				int newy = y;
				int dx = dir[i][0];
				int dy = dir[i][1];
				while(newx+dx >= 0 && newx+dx < n && newy+dy >= 0 && newy+dy < m){
					newx += dx;
					newy += dy;
					ans += dp[newx][newy];
				}
			}
			dp[x][y] = ans;
		}
	}
	return dp[X][Y];
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("./../IO/input.txt","r",stdin);
        freopen("./../IO/output.txt","w",stdout);
        freopen("./../IO/error.txt", "w", stderr);
    #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n>>m;
	vector<vector<int>> dp(n,vector<int>(m,-1));
	int ans = maze_path_tab(n-1,m-1,dp);
	cout<<ans<<"\n";
	print(dp);
	return 0;
}
