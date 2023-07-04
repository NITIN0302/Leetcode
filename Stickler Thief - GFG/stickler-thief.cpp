//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int index,int arr[],int n,vector<int> &dp)
    {
        if(index >= n)
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int include = arr[index] + solve(index+2,arr,n,dp);
        
        int exclude = solve(index+1,arr,n,dp);
        
        return dp[index] = max(include,exclude);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1,-1);
        return solve(0,arr,n,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends