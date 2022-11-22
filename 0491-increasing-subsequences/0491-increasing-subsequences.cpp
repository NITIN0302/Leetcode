class Solution {
public:
    
    void solve(int index,vector<int> &nums,vector<int> &output,set<vector<int>> &ans,int back)
    {
        if(index >= nums.size())
        {
            if(output.size() > 1)
            {
                ans.insert(output);
            }
            return;
        }
        
        if(nums[index] < back)
        {
            solve(index+1,nums,output,ans,back);
        }
        else
        {
            solve(index+1,nums,output,ans,back);
            
            
            output.push_back(nums[index]);
            solve(index+1,nums,output,ans,nums[index]);
            output.pop_back();
        }
        
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        set<vector<int>> ans1;
        vector<int> output;
        for(int i=0;i<nums.size()-1;i++)
        {
            output.push_back(nums[i]);
            solve(i+1,nums,output,ans1,nums[i]);
            output.pop_back();
        }
        vector<vector<int>> ans;
        for(auto i:ans1)
        {
            ans.push_back(i);
        }
        return ans;
    }
};