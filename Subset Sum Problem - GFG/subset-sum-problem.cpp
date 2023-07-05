//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution
{   
public:

    int solve(int index,vector<int> &arr,int target,vector<vector<int>> &dp)
    {
        if(target == 0)
        {
            return 1;
        }
        if(target < 0)
        {
            return 0;
        }
        if(index >= arr.size())
        {
            return 0;
        }
        
        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }
        
        int exclude = solve(index+1,arr,target,dp);
        
        int include = solve(index+1,arr,target-arr[index],dp);
        
        return dp[index][target] = (include || exclude);
    }

    bool isSubsetSum(vector<int>arr, int sum)
    {
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
        return solve(0,arr,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends