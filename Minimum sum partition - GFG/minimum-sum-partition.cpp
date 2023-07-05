//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
    int solve(int index,int arr[],int sum,int total,vector<vector<int>> &dp)
    {
        if(index < 0)
        {
            return abs(abs(total-sum) - sum);
        }
        
        if(dp[index][sum] != -1)
        {
            return dp[index][sum];
        }
        
        int include = solve(index-1,arr,sum,total,dp);
        
        int exclude = solve(index-1,arr,sum + arr[index],total,dp);
        
        return dp[index][sum] = min(include,exclude);
    }
  
	int minDifference(int arr[], int n)  
	{
	    int sum = 0;
	    for(int i=0;i<n;i++)
	    {
	        sum += arr[i];
	    }
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	    return solve(n-1,arr,0,sum,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends