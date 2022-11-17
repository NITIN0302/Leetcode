class Solution {
public:
    set<string> s;
    int fact[8] = {1,1,2,6,24,120,720,5040};
    
    
    int solve(string st)
    {
        int count[26] = {0};
        int res;
        for(auto i:st) 
            count[i-'A']++;
        res =  fact[st.length()];
        for(auto i:count)
        {
            res = res/fact[i];
        }
        return res;
    }
    
    
    void permutation(int index,set<string> &s,string output,string &tiles,int &ans)
    {
        if(index >= tiles.length())
        {
            if(s.find(output) == s.end() && output.length() != 0)
            {
                ans += (solve(output));
                s.insert(output);
            }
            return;
        }
        
        permutation(index+1,s,output,tiles,ans);
        
        output.push_back(tiles[index]);
        permutation(index+1,s,output,tiles,ans);
    }
    
    int numTilePossibilities(string tiles) 
    {
        sort(tiles.begin(),tiles.end());
        int ans = 0;
        string output;
        permutation(0,s,output,tiles,ans);
        return ans;
    }
};