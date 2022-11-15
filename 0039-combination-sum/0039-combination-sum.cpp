class Solution {
public:
    
    void solve(int index,vector<int> &value,vector<int> output,vector<vector<int>> &ans,int target)
    {
        if(target == 0)
        {
            ans.push_back(output);
            return;
        }
        if(index >= value.size())
        {
            return;
        }
        for(int i=index;i<value.size();i++)
        {
            if(target - value[i] >= 0)
            {
                output.push_back(value[i]);
                solve(i,value,output,ans,target-value[i]);
                output.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> output;
        vector<vector<int>> ans;
        solve(0,candidates,output,ans,target);
        return ans;
    }
};