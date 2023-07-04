//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
  
    int solve(int index,vector<int> &height,int n,vector<int> &dp)
    {
        if(index == n)
        {
            return 0;
        }
        if(index > n)
        {
            return 1e9;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int jump1 = 1e9,jump2 = 1e9;
        
        if(index+1 <= n)
            jump1 = abs(height[index+1] - height[index]) + solve(index+1,height,n,dp);
        
        if(index+2 <= n)
        jump2 = abs(height[index+2] - height[index]) + solve(index+2,height,n,dp);
        
        return dp[index] = min(jump1,jump2);
    }
  
    int minimumEnergy(vector<int>& height, int n) 
    {
        vector<int> dp(n+1,-1);
        return solve(0,height,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends