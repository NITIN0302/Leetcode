class Solution {
public:
    
    void solve(int k,char p,string &output,vector<string> &ans)
    {
        if(k==0)
        {
            ans.push_back(output);
            return;
        }
        for(char s='a';s<='c';s++)
        {
            if(p != s)
            {
                output.push_back(s);
                solve(k-1,s,output,ans);
                output.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k)
    {
        vector<string> ans;
        string output;
        for(char p='a';p<='c';p++)
        {
            output.push_back(p);
            solve(n-1,p,output,ans);
            output.pop_back();
        }
        sort(ans.begin(),ans.end());
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
        if(ans.size() < k)
        {
            return "";
        }
        return ans[k-1];
    }
};