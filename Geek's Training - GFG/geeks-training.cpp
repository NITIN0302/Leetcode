//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
  
    int solve(int row,int col,vector<vector<int>>& points,vector<vector<int>> &dp)
    {
        if(row >= points.size())
        {
            return 0;
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int ans = INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(i != col)
            {
                ans = max(ans,solve(row+1,i,points,dp));
            }
        }
        return dp[row][col] = points[row][col] + ans;
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        vector<vector<int>> dp(n,vector<int>(3,-1));
        int ans = INT_MIN;
        for(int i=0;i<3;i++)
        {
            ans = max(ans,solve(0,i,points,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends