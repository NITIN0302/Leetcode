class Solution {
public:
    
    void solve(int index,unordered_map<char,int> &used,string pattern,string &ans,string &result)
    {
        if(index >= pattern.length())
        {
            result = ans;
            return;
        }
        
        if(pattern[index] == 'I')
        {
            for(char i='9';i>ans[index];i--)
            {
                if(used[i] == 1)
                    continue;
                ans.push_back(i);
                used[i] = 1;
                solve(index+1,used,pattern,ans,result);
                ans.pop_back();
                used[i] = 0;
            }
        }
        else
        {
            for(char i='1';i<ans[index];i++)
            {
                if(used[i] == 1) 
                    continue;
                
                ans.push_back(i);
                used[i] = 1;
                solve(index+1,used,pattern,ans,result);
                ans.pop_back();
                used[i] = 0;
            }
        }
    }
    
    string smallestNumber(string pattern) 
    {
        string result;
        string ans;
        unordered_map<char,int> used;
        for(char i='1';i<='9';i++)
        {
            used[i] = 1;
            ans.push_back(i);
            solve(0,used,pattern,ans,result);
            if(result.length() > pattern.length())
            {
                return result;
            }
            used[i] = 0;
            ans.pop_back();
        }
        return result;
    }
};