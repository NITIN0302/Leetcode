class Solution {
public:
    
    void solve(int n,int k,int p,vector<int> &output,vector<vector<int>> &ans)
    {
        if(k == 0)
        {
            ans.push_back(output);
            return;
        }
        for(int i=p;i<=n;i++)
        {
            output.push_back(i);
            solve(n,k-1,i+1,output,ans);
            output.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> output;
        for(int i=1;i<=n;i++)
        {
            output.push_back(i);
            solve(n,k-1,i+1,output,ans);
            output.pop_back();
        }
        return ans;
    }
};