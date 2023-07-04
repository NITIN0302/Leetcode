//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution
{
public:	

    int solve(int index,int *arr,vector<int> &dp,int n)
    {
        if(index >= n)
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int exclude = solve(index+1,arr,dp,n);
        
        int include = arr[index] + solve(index+2,arr,dp,n);
        
        return dp[index] = max(include,exclude);
    }

	int findMaxSum(int *arr, int n) 
	{
	    vector<int> dp(n+1,-1);
	    return solve(0,arr,dp,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends