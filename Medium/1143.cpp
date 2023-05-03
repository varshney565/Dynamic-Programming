class Solution {
public:
    
    int longestCommonSubsequence(string a, string b) {
        int N = a.size();
        int M = b.size();
        vector<vector<int>> dp(N+1,vector<int>(M+1,0));
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
};