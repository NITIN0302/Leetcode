//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long solve(int start,int end,int arr[],vector<vector<long long>> &dp)
    {
        if(start > end) return 0;
        if(start == end) return arr[start];
        
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        
        long long st,en;
        
        st = arr[start] + min(solve(start+2,end,arr,dp),solve(start+1,end-1,arr,dp));
        
        en = arr[end] + min(solve(start,end-2,arr,dp),solve(start+1,end-1,arr,dp));
        
        return dp[start][end] = max(st,en);
    }
   
    long long maximumAmount(int arr[], int n)
    {
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
        return solve(0,n-1,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends