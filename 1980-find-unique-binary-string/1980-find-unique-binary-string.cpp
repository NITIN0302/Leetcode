class Solution {
public:
    
    void solve(int n,unordered_map<string,bool> &m,string &output,string &ans)
    {
        if(n == 0)
        {
            if(m[output] == false)
            {
                ans = output;
            }
            return;
        }
        for(int i=0;i<2;i++)
        {
            output += (i+'0');
            solve(n-1,m,output,ans);
            output.pop_back();
        }
    }
    
    
    string findDifferentBinaryString(vector<string>& nums) 
    {
        unordered_map<string,bool> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]] = true;
        }
        
        int n = nums[0].length();
        string output;
        string ans;
        solve(n,m,output,ans);
        return ans;
    }
};