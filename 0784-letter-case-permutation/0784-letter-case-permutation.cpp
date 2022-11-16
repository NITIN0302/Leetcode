class Solution {
public:
    
    char changecase(char a)
    {
        if(a >= 'a' && a <= 'z')
        {
            return a-32;
        }
        return a+32;
    }
    
    void solve(int index,vector<string> &ans,string &s)
    {
        if(index >= s.length())
        {
            ans.push_back(s);
            return;
        }
        
        if(s[index] >= '0' && s[index] <= '9')
        {
            solve(index+1,ans,s);
        }
        else
        {
            solve(index+1,ans,s);
            
            s[index] = changecase(s[index]);
            solve(index+1,ans,s);
            s[index] = changecase(s[index]);
        }
    }
    
    vector<string> letterCasePermutation(string s) 
    {
        vector<string> ans;
        solve(0,ans,s);
        return ans;
    }
};