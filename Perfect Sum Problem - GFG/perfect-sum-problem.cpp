//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int mod = 1e9 + 7;
	int solve(int index,int n,int arr[],int sum,vector<vector<int>> &dp)
	{
	    if(sum < 0)return 0;
	    if(index >= n)
	    {
	        if(sum == 0)
	        {
	            return 1;
	        }
	        return 0;
	    }
	    
	    if(dp[index][sum] != -1)
	    {
	        return dp[index][sum];
	    }
	    
	    //exclude
	    int exc = solve(index+1,n,arr,sum,dp);
	    
	   // include
	    int inc = solve(index+1,n,arr,sum-arr[index],dp);
	   
	    
	    return dp[index][sum] = (inc + exc)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(0,n,arr,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends