//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution 
{
  public:
  
    int solve(int index,vector<int> &A,int target,unordered_map<string,int> &dp)
    {
        if(index >= A.size())
        {
            if(target == 0)
            {
                return 1;
            }
            return 0;
        }
        
        string s = to_string(index);
        s += to_string(target);
        if(dp.find(s) != dp.end())
        {
            return dp[s];
        }
        
        int add = solve(index+1,A,target+A[index],dp);
        
        int sub = solve(index+1,A,target-A[index],dp);
        
        return dp[s] = (add + sub);
    }
  
    int findTargetSumWays(vector<int>&A ,int target) 
    {
        unordered_map<string,int> dp;
        return solve(0,A,target,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends