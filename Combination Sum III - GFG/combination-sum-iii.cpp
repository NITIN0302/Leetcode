//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void solve(int index,int k,int sum, vector<int> &temp,vector<bool> &used,
    vector<vector<int>> &ans)
    {
        if(sum == 0 && k == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(index >= 10 || sum < 0 || k < 0)
        {
            return;
        }
        
        for(int i=index;i<=9;i++)
        {
            if(used[i] == false)
            {
                used[i] = true;
                temp.push_back(i);
                solve(i+1,k-1,sum-i,temp,used,ans);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
  
    vector<vector<int>> combinationSum(int K, int N) 
    {
        vector<vector<int>> ans;
        vector<bool> used(10,false);
        vector<int> temp;
        solve(1,K,N,temp,used,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends