class Solution {
public:
    
    void solve(int index,vector<int> &value,vector<int> output,set<vector<int>> &ans,int target)
    {
        if(target == 0)
        {
            ans.insert(output);
            return;
        }
        if(index >= value.size())
        {
            return;
        }
        
        for(int i=index;i<value.size();i++)
        {
            if(i>index && value[i] == value[index])
                continue;
            if(value[i] <= target)
            {
                output.push_back(value[i]);
                solve(i+1,value,output,ans,target-value[i]);
                output.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        
        vector<int> output;
        set<vector<int>> ans1;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,output,ans1,target);
        vector<vector<int>> ans;
        for(auto i:ans1)
        {
            ans.push_back(i);
        }
        return ans;
    }
};