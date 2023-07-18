//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int solve(int index,int M,int coins[],int V,vector<vector<int>> &dp)
	{
	    if(V == 0)
	    {
	        return 0;
	    }
	    if(index >= M)
	    {
	        return 1e9;
	    }
	    if(V < 0)
	    {
	        return 1e9;
	    }
	    if(dp[V][index] != -1)
	    {
	        return dp[V][index];
	    }
	    int inc=1e9,exc=1e9;
	    if(coins[index] <= V)
	    {
	        inc = 1 + solve(index,M,coins,V-coins[index],dp);
	        
	        exc = solve(index+1,M,coins,V,dp);
	    }
	    else
	    {
	        exc = solve(index+1,M,coins,V,dp);
	    }
	    
	    return dp[V][index] = min(inc,exc);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(V+1,vector<int>(M+1,-1));
	    int ans = solve(0,M,coins,V,dp);
	    if(ans == 1e9)return -1;
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends