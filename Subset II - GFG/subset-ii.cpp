//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
  
  void solve(int index,vector<int> &nums,vector<int> &temp,set<vector<int>> &s)
  {
      if(index >= nums.size())
      {
          s.insert(temp);
          return;
      }
      
      //   exclude
      solve(index+1,nums,temp,s);
      
      //   include
      temp.push_back(nums[index]);
      solve(index+1,nums,temp,s);
      temp.pop_back();
  }
  
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans1;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,temp,ans1);
        for(auto i:ans1)
        {
            ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends