//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	int solve(int i,int j, string s1,string s2,vector<vector<int>> &dp)
	{
	    if(i<=0)
	    {
	        return j;
	    }
	    if(j<=0)
	    {
	        return i;
	    }
	    if(dp[i][j] != -1)return dp[i][j];
	    
	    if(s1[i-1] == s2[j-1])
	    {
	        return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
	    }
	    else
	    {
	        return dp[i][j] = 1 + min(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
	    }
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,-1));
	    
	    return solve(str1.length(),str2.length(),str1,str2,dp);
	    
	    
	   // for(int i=1;i<=str2.length();i++)
	   // {
	   //     dp[0][i] = i;
	   // }
	    
	   // for(int i=1;i<=str1.length();i++)
	   // {
	   //     dp[i][0] = i;
	   // }
	    
	   // for(int i=0;i<=str1.length();i++)
	   // {
	   //     for(int j=0;j<=str2.length();j++)
	   //     {
	   //         cout<<dp[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    
	   // for(int i=1;i<=str1.length();i++)
	   // {
	   //     for(int j=1;j<=str2.length();j++)
	   //     {
	   //         if(str1[i-1] == str2[j-1])
	   //         {
	   //             dp[i][j] = dp[i-1][j-1];
	   //         }
	   //         else
	   //         {
	   //             dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
	   //         }
	   //     }
	   // }
	   // return dp[str1.length()][str2.length()];
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends