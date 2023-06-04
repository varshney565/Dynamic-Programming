//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
       function<int(int,int)> go = [&](int weight,int n){
           if(n == 0 || weight == 0) return dp[n][weight] = 0;
           if(dp[n][weight] != -1) return dp[n][weight];
           int value = 0;
           //take 
           if(weight-wt[n-1] >= 0)
                value = val[n-1]+go(weight-wt[n-1],n-1);
           //ignore
           value = max(value,go(weight,n-1));
           return dp[n][weight] = value;
       };
       return go(W,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends