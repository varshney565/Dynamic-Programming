class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(n == 0 || m == 0) return dp[n][m] = -10000000;
            if(dp[n][m] != -1) return dp[n][m];
            int ans = nums1[n-1]*nums2[m-1];
            int op1 = nums1[n-1]*nums2[m-1]+go(n-1,m-1);
            int op2 = go(n-1,m);
            int op3 = go(n,m-1);
            ans = max({ans,op1,op2,op3});
            return dp[n][m] = ans;
        };
        return go(n,m);
    }
};