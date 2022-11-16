class Solution {
public:
    
    void solve(int index,vector<int> &output,map<vector<int>,bool> &ans,vector<int> &nums)
    {
        if(index >= nums.size())
        {
            ans[output] = true;
            return;
        }
        
        solve(index+1,output,ans,nums);
        
        output.push_back(nums[index]);
        solve(index+1,output,ans,nums);
        output.pop_back();
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        map<vector<int>,bool> ans1;
        vector<int> output;
        
        sort(nums.begin(),nums.end());
        
        solve(0,output,ans1,nums);
        vector<vector<int>> ans;
        for(auto i:ans1)
        {
            ans.push_back(i.first);
        }
        return ans;
    }
};