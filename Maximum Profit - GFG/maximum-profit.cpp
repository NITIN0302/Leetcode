//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
  
    int solve(int index,int k,int N,int isbuy,int A[],vector<vector<vector<int>>> &dp)
    {
        if(index >= N || k == 0)
        {
            return 0;
        }
        
        if(dp[index][k][isbuy] != -1)
        {
            return dp[index][k][isbuy];
        }
        
        int profit;
        
        if(isbuy)
        {
            profit = max(-A[index] + solve(index+1,k,N,!isbuy,A,dp),solve(index+1,k,N,isbuy,A,dp));
        }
        else
        {
            profit = max(A[index] + solve(index+1,k-1,N,!isbuy,A,dp),solve(index+1,k,N,isbuy,A,dp));
        }
        
        dp[index][k][isbuy] = profit;
    }
  
    int maxProfit(int K, int N, int A[]) 
    {
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(K+1,vector<int>(2,-1)));
        
        return solve(0,K,N,1,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends