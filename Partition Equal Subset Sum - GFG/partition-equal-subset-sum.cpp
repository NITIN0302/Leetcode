//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:

    int solve(int index,int arr[],int sum,vector<vector<int>> &dp)
    {
        if(sum < 0)
        {
            return 0;
        }
        if(sum == 0)
        {
            return 1;
        }
        if(index < 0)
        {
            return false;
        }
        
        if(dp[index][sum] != -1)
        {
            return dp[index][sum];
        }
        
        int exclude = solve(index-1,arr,sum,dp);
        
        int include = solve(index-1,arr,sum-arr[index],dp);
        
        return dp[index][sum] = (include || exclude);
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
        }
        if(sum%2 == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(N+1,vector<int>(sum/2+1,-1));
        return solve(N-1,arr,sum/2,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends