//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++



//memoization
/**
class Solution{
public:
    int matrixMultiplication(int n, int arr[]){
        vector<vector<int>> dp(n,vector<int>(n,-1));
        function<int(int,int)> go = [&](int st,int en){
            if(en - st == 1) return dp[st][en] = 0;
            if(dp[st][en] != -1) return dp[st][en];
            int ans = 1e9;
            for(int cut = st + 1 ; cut < en ; cut++){
                int leftAns = go(st,cut);
                int rightAns = go(cut,en);
                ans = min(ans,leftAns+rightAns+arr[st]*arr[cut]*arr[en]);
            }
            return dp[st][en] = ans;
        };
        return go(0,n-1);
    }
};
*/


//Tabulation
class Solution{
public:
    int matrixMultiplication(int n, int arr[]){
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int st = n-1 ; st >= 0 ; st--){
            for(int en = 0 ; en < n ; en++){
                if(en - st == 1) {
                    dp[st][en] = 0;
                    continue;
                }
                for(int cut = st + 1 ; cut < en ; cut++){
                    dp[st][en] = min(dp[st][en],dp[st][cut]+dp[cut][en]+arr[st]*arr[cut]*arr[en]);
                }
            }
        }
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends