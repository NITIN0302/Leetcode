class Solution {
public:
    
    void solve(int k,int n,vector<int> output,vector<vector<int>> &ans)
    {
        if(k==0)
        {
            if(n==0)
            {
                ans.push_back(output);
            }
            return;
        }
        for(int i=output.back()+1;i<=9;i++)
        {
            
                output.push_back(i);
                solve(k-1,n-i,output,ans);
                output.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
      
        vector<vector<int>> ans;
        vector<int> output;
        for(int i=1;i<=9;i++)
        {
            output.push_back(i);
            
            solve(k-1,n-i,output,ans);
           
            output.pop_back();
        }
        return ans;
    }
};