//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int solve(int i,int j,string s,string t,vector<vector<int>> &dp)
    {
        if(i <= 0)
        {
            return j;
        }
        if(j <= 0)
        {
            return i;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(s[i-1] == t[j-1])
        {
            return dp[i][j] = solve(i-1,j-1,s,t,dp);
        }
        return dp[i][j] = 1 + min({solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp),solve(i-1,j-1,s,t,dp)});
    }
  
    int editDistance(string s, string t) 
    {
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,-1));
        
        return solve(s.length(),t.length(),s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends