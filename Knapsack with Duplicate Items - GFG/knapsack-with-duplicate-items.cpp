//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:

    int solve(int index,int w,int val[],int wt[],vector<vector<int>> &dp)
    {
        if(index < 0 || w <= 0)
        {
            return 0;
        }
        if(dp[index][w] != -1)
        {
            return dp[index][w];
        }
        
        int nottake = solve(index-1,w,val,wt,dp);
        
        int take = INT_MIN;
        
        if(w >= wt[index])
        {
            take = val[index] + solve(index,w-wt[index],val,wt,dp);
        }
        else
        {
            take = solve(index-1,w,val,wt,dp);
        }
        
        return dp[index][w] = max(take,nottake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends