//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
     long long solve(int index,vector<long long> &prices,int isbuy,vector<vector<long long>> &dp)
    {
        if(index >= prices.size())
        {
            return 0;
        }
        
        if(dp[index][isbuy] != -1)
        {
            return dp[index][isbuy];
        }
        
        int profit;
        
        if(isbuy)
        {
            profit = max(-prices[index] + solve(index+1,prices,!isbuy,dp),solve(index+1,prices,isbuy,dp));
        }
        else
        {
            profit = max(prices[index] + solve(index+1,prices,!isbuy,dp),solve(index+1,prices,isbuy,dp));
        }
        
        return dp[index][isbuy] = profit;
    }
    
    
    long long maximumProfit(vector<long long>&prices, int n) 
    {
        vector<vector<long long>> dp(prices.size()+1,vector<long long>(2,-1));
        
        return solve(0,prices,1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends